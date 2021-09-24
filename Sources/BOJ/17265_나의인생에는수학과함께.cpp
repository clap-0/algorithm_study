#include <iostream>
#include <algorithm>
using namespace std;
int dp[2][5][5];
char map[5][5];
// op에 따라 a와 b를 연산한다
int calc(int a, int b, int op){
  switch(op){
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) cin >> map[i][j];
  // 최댓값과 최솟값을 쉽게 구하기 위해 각 칸에서의 최댓값은 아주 작은 음수값으로, 최솟값은 매우 큰 양수값으로 초기화한다
  fill((int*)dp[0], (int*)(dp[0]+5), -987654321);
  fill((int*)dp[1], (int*)(dp[1]+5), 987654321);
  // 시작지점에서의 최댓값과 최솟값은 해당 칸의 수와 같다
  dp[0][0][0]=dp[1][0][0]=map[0][0]-'0';
  // map[i][j]가 연산자인 경우 이전에 지나온 칸에서 해당 칸을 지나가는 모든 칸에 대해 최댓값과 최솟값을 구한다
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
      if(i+j==0) continue;
      if('0'<=map[i][j]&&map[i][j]<='5') continue;
      // 이전에 지나온 칸이 바로 윗칸인 경우
      if(i>=1){
        // 아랫칸으로 가는 경우
        if(i+1<N){
          dp[0][i+1][j]=max(dp[0][i+1][j], calc(dp[0][i-1][j], map[i+1][j]-'0', map[i][j]));
          dp[1][i+1][j]=min(dp[1][i+1][j], calc(dp[1][i-1][j], map[i+1][j]-'0', map[i][j]));
        }
        // 오른쪽 칸으로 가는 경우
        if(j+1<N){
          dp[0][i][j+1]=max(dp[0][i][j+1], calc(dp[0][i-1][j], map[i][j+1]-'0', map[i][j]));
          dp[1][i][j+1]=min(dp[1][i][j+1], calc(dp[1][i-1][j], map[i][j+1]-'0', map[i][j]));
        }
      }
      // 이전에 지나온 칸이 왼쪽칸인 경우
      if(j>=1){
        // 아랫칸을 가는 경우
        if(i+1<N){
          dp[0][i+1][j]=max(dp[0][i+1][j], calc(dp[0][i][j-1], map[i+1][j]-'0', map[i][j]));
          dp[1][i+1][j]=min(dp[1][i+1][j], calc(dp[1][i][j-1], map[i+1][j]-'0', map[i][j]));
        }
        // 오른쪽 칸으로 가는 경우
        if(j+1<N){
          dp[0][i][j+1]=max(dp[0][i][j+1], calc(dp[0][i][j-1], map[i][j+1]-'0', map[i][j]));
          dp[1][i][j+1]=min(dp[1][i][j+1], calc(dp[1][i][j-1], map[i][j+1]-'0', map[i][j]));
        }
      }
    }
  cout << dp[0][N-1][N-1] << ' ' << dp[1][N-1][N-1] << '\n';
}

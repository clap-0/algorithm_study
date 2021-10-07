#include <iostream>
using namespace std;
int value[201][2], dp[201][200][3];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, K;
  cin >> N >> K;
  for(int i=1; i<=N; i++) {
    cin >> value[i][0] >> value[i][1];
  }
  // 반복적 동적계획법
  // dp[n][k][i] = n번 줄이 i번째 상태이고 지금까지 k개의 방을 닫았을 때 가치의 최대합
  // i==0일 때 두 칸중 오른쪽만 닫힌 경우 ◇◆
  dp[1][1][0]=value[1][0];
  // i==1일 때 두 칸중 왼쪽만 닫힌 경우 ◆◇
  dp[1][1][1]=value[1][1];
  // i==2일 때 두 칸 모두 열린 경우 ◇◇
  dp[1][0][2]=value[1][0]+value[1][1];
  for(int n=2; n<=N; n++){
    for(int k=0; k<=n; k++){
      if(k>0){
        // 현 상태가 0번이면 이전 상태는 0번이거나 2번이다
        dp[n][k][0]=max(dp[n-1][k-1][0], dp[n-1][k-1][2])+value[n][0];
        // 현 상태가 1번이면 이전 상태는 1번이나 2번이다
        dp[n][k][1]=max(dp[n-1][k-1][1], dp[n-1][k-1][2])+value[n][1];
      }
      // 현 상태가 2번이면 이전 상태는 3개 다 가능하다
      if(n!=k) dp[n][k][2]=max(dp[n-1][k][0], max(dp[n-1][k][1], dp[n-1][k][2]))+value[n][0]+value[n][1];
    }
  }
  cout << max(dp[N][K][0], max(dp[N][K][1], dp[N][K][2])) << '\n';
}

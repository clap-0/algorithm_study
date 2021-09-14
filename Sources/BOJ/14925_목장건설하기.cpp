#include <iostream>
using namespace std;
int M, N, L=0, isObstacle;
//dp[i][j] = i행j열을 오른쪽아래칸으로 하는 가능한 가장 큰 정사각형의 변의 길이
int dp[1001][1001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> M >> N;
  //메모이제이션
  for(int i=1; i<=M; i++)
    for(int j=1; j<=N; j++){
      cin >> isObstacle;
      //i행j열칸이 평원인 경우
      //i-1행j열, i행j열, i-1행j-1열칸을 각각 오른쪽아래칸으로 하는 가능한 가장 큰 정사각형들 중
      //가장 작은 정사각형의 길이+1이 된다
      if(!isObstacle){
        dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
        L=max(L, dp[i][j]);
      }
    }
  cout << L << '\n';
}

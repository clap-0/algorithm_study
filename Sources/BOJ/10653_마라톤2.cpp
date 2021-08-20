#include <iostream>
using namespace std;
int N, K;
int dp[500][501], dist[501][501];
pair<int,int> checkpoint[501];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> K;
  for(int i=1; i<=N; i++) cin >> checkpoint[i].first >> checkpoint[i].second;
  //두 체크포인트 사이의 택시거리를 미리 계산한다
  for(int i=1; i<=N; i++)
    for(int j=i; j<=N; j++)
      dist[i][j]=abs(checkpoint[i].first-checkpoint[j].first)+abs(checkpoint[i].second-checkpoint[j].second);
  //반복적 동적계획법
  for(int n=2; n<=N; n++) dp[K][n]=dp[K][n-1]+dist[n-1][n];
  for(int k=K-1; k>=0; k--)
    for(int n=2; n<=N; n++){
      dp[k][n]+=dp[k][n-1]+dist[n-1][n];
      for(int i=2; i<n&&i<K-k+2; i++)
        dp[k][n]=min(dp[k][n], dp[k+i-1][n-i]+dist[n-i][n]);
    }
  cout << dp[0][N] << '\n';
}

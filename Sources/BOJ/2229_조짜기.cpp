#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000][1000];
int score[1000];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> score[i];
  //반복적동적계획법
  for(int i=1; i<N; i++)
    for(int n=0; n+i<N; n++){
      dp[n][n+i]=*max_element(score+n, score+n+i+1)-*min_element(score+n, score+n+i+1);
      for(int k=n+i-1; k>=n; k--) dp[n][n+i]=max(dp[n][n+i], dp[n][k]+dp[k+1][n+i]);
    }
  cout << dp[0][N-1] << '\n';
}

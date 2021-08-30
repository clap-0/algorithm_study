#include <iostream>
using namespace std;
int dp[100][100001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, K, a, b, c, d;
  cin >> N >> K;
  //반복적동적계획법
  cin >> a >> b >> c >> d;
  dp[0][a]=b;
  dp[0][c]=max(dp[0][c], d);
  for(int i=1; i<N; i++){
    cin >> a >> b >> c >> d;
    for(int j=0; j<=K; j++)
      if(dp[i-1][j]!=0){
        if(K>=j+a) dp[i][j+a]=max(dp[i][j+a], dp[i-1][j]+b);
        if(K>=j+c) dp[i][j+c]=max(dp[i][j+c], dp[i-1][j]+d);
      }
  }
  int ans=0;
  for(int k=0; k<=K; k++) ans=max(ans, dp[N-1][k]);
  cout << ans << '\n';
}

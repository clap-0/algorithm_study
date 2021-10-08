#include <iostream>
using namespace std;
int dp[1001][1001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, K;
  cin >> N >> K;
  // ₙC₀==1
  for(int i=0; i<=N; i++) dp[i][0]=1;
  // ₙCₖ = ₙ₋₁Cₖ + ₙ₋₁Cₖ₋₁
  for(int n=1; n<=N; n++)
    for(int k=1; k<=n; k++) dp[n][k]=(dp[n-1][k]+dp[n-1][k-1])%10007;
  cout << dp[N][K] << '\n';
}

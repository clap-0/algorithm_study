#include <iostream>
using namespace std;

const int MOD = 1e9+7;
int dp[1001][1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  dp[1][0] = dp[1][1] = 1;
  for (int i = 2; i <= 1000; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= i; j++)
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
  }

  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, k;
    cin >> n >> k;
    cout << dp[n][k] << '\n';
  }
}

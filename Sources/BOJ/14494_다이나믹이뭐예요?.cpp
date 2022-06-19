#include <iostream>
using namespace std;

const int MOD = 1000000007;
int dp[1001][1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  dp[0][0] = 1;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
      dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
      dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
    }

  cout << dp[n][m] << '\n';
}

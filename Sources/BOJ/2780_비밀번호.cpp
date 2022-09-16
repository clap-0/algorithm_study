#include <iostream>
using namespace std;

const int MOD = 1234567;
int dp[1001][10];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  for (int num = 0; num < 10; num++)
    dp[1][num] = 1;

  for (int i = 2; i <= 1000; i++)
    for (int num = 0; num < 10; num++)
      switch (num) {
        case 0: dp[i][num] = (dp[i - 1][7]) % MOD;
        break;
        case 1: dp[i][num] = (dp[i - 1][2] + dp[i - 1][4]) % MOD;
        break;
        case 2: dp[i][num] = (dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]) % MOD;
        break;
        case 3: dp[i][num] = (dp[i - 1][2] + dp[i - 1][6]) % MOD;
        break;
        case 4: dp[i][num] = (dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]) % MOD;
        break;
        case 5: dp[i][num] = (dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]) % MOD;
        break;
        case 6: dp[i][num] = (dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]) % MOD;
        break;
        case 7: dp[i][num] = (dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0]) % MOD;
        break;
        case 8: dp[i][num] = (dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]) % MOD;
        break;
        case 9: dp[i][num] = (dp[i - 1][6] + dp[i - 1][8]) % MOD;
        break;
      }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < 10; i++)
      ans += dp[n][i];
    cout << ans % MOD << '\n';
  }
}

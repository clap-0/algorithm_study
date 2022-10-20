#include <iostream>
using namespace std;

int dp[31];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k; n--; k--;

  dp[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = min(i, k); j > 0; j--)
      dp[j] += dp[j - 1];
  
  cout << dp[k] << '\n';
}

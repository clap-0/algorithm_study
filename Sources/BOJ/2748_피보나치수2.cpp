#include <iostream>
using namespace std;

long long dp[91];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  dp[0] = 0, dp[1] = 1;
  for(int i = 2; i <= N; i++)
    dp[i] = dp[i - 1] + dp[i - 2];

  cout << dp[N] << '\n';
}

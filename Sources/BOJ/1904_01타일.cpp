#include <iostream>
using namespace std;

int dp[3];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  dp[1] = 1, dp[2] = 2;
  for (int i = 3; i <= N; i++)
    dp[i % 3] = (dp[(i - 1) % 3] + dp[(i - 2) % 3]) % 15746;
  cout << dp[N % 3] << '\n';
}

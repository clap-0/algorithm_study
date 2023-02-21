#include <iostream>
using namespace std;

int strength[2000];
int dp[2000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  int ans = N;
  for (int i = 0; i < N; i++) {
    cin >> strength[i];
    dp[i] = 1;
    for (int j = 0; j < i; j++)
      if (strength[j] > strength[i])
        dp[i] = max(dp[i], 1 + dp[j]);
    ans = min(ans, N - dp[i]);
  }

  cout << ans << '\n';
}

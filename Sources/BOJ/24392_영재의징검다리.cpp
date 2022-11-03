#include <iostream>
using namespace std;

int dp[1000][1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> dp[i][j];

  for (int i = 1; i < N; i++)
    for (int j = 0; j < M; j++)
      if (dp[i][j]) {
        dp[i][j] = dp[i - 1][j];
        if (j - 1 >= 0)
          dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000000007;
        if (j + 1 < M)
          dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % 1000000007;
      }
  
  int ans = 0;
  for (int i = 0; i < M; i++)
    ans = (ans + dp[N - 1][i]) % 1000000007;
  cout << ans << '\n';
}

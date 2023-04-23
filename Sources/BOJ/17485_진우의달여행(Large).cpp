#include <iostream>
using namespace std;

int dp[2][1000][3];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;

  int fuel;
  for (int j = 0; j < M; j++) {
    cin >> fuel;
    dp[0][j][0] = dp[0][j][1] = dp[0][j][2] = fuel;
  }

  dp[0][0][2] = dp[1][0][2] = 987654321;
  dp[0][M - 1][0] = dp[1][M - 1][0] = 987654321;

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> fuel;
      if (j + 1 < M) 
        dp[i % 2][j][0] = fuel + min(dp[(i - 1) % 2][j + 1][1], dp[(i - 1) % 2][j + 1][2]);
      dp[i % 2][j][1] = fuel + min(dp[(i - 1) % 2][j][0], dp[(i - 1) % 2][j][2]);
      if (j > 0)
        dp[i % 2][j][2] = fuel + min(dp[(i - 1) % 2][j - 1][0], dp[(i - 1) % 2][j - 1][1]);
    }
  }

  int ans = 987654321;
  for (int j = 0; j < M; j++) {
    ans = min(ans, dp[(N - 1) % 2][j][0]);
    ans = min(ans, dp[(N - 1) % 2][j][1]);
    ans = min(ans, dp[(N - 1) % 2][j][2]);
  }

  cout << ans << '\n';
}

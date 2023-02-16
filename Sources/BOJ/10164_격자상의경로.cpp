#include <iostream>
using namespace std;

int dp[29][15];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M, K;
  cin >> N >> M >> K;

  dp[0][0] = 1;
  for (int i = 1; i < N + M - 1; i++) {
    for (int j = min(i, (N + M - 1) / 2); j >= 1; j--)
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    dp[i][0] = dp[i - 1][0];
  }
  
  int ans;
  if (K == 0) {
    ans = dp[N + M - 2][min(N, M) - 1];
  }
  else {
    int row = (K - 1) / M, col = (K - 1) % M;
    ans = dp[row + col][min(row, col)];
    ans *= dp[N + M - row - col - 2][min(N - row, M - col) - 1];
  }
  cout << ans << '\n';
}

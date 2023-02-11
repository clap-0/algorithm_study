#include <iostream>
using namespace std;

string D[2000];
int dp[2000][2];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int M, N;
  cin >> M >> N;
  for (int i = 0; i < M; i++) {
    cin >> D[i];
  }

  for (int j = 0; j < N - 1; j++) {
    for (int i = 0; i < M; i++) {
      dp[i][(j + 1) % 2] = max(dp[i][(j + 1) % 2], D[i][j] - '0' + dp[i][j % 2]);
      
      if (i > 0) {
        dp[i - 1][(j + 1) % 2] = max(dp[i - 1][(j + 1) % 2], D[i][j] - '0' + dp[i][j % 2]);
      }
      
      if (i < M - 1) {
        dp[i + 1][(j + 1) % 2] = max(dp[i + 1][(j + 1) % 2], D[i][j] - '0' + dp[i][j % 2]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < M; i++) {
    ans = max(ans, dp[i][(N - 1) % 2]);
  }
  
  cout << ans << '\n';
}

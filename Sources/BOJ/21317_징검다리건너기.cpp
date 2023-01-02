#include <iostream>
using namespace std;

// dp[i][0] = i번 돌까지 매우 큰 점프 없이 도달하는데 필요한 에너지
// dp[i][1] = i번 돌까지 매우 큰 점프를 한 번 하고 도달하는데 필요한 에너지
int dp[20][2];
int small[19], big[19];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, K;
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    cin >> small[i] >> big[i];
    dp[i + 1][0] = dp[i + 1][1] = 987654321;  // dp를 INF로 초기화
  }
  cin >> K;

  for (int i = 0; i < N - 1; i++) {
    // i번 돌에서 작은 점프를 하는 경우
    dp[i + 1][0] = min(dp[i + 1][0], small[i] + dp[i][0]);
    dp[i + 1][1] = min(dp[i + 1][1], small[i] + dp[i][1]);
    // i번 돌에서 큰 점프를 하는 경우
    if (i + 2 < N) {
      dp[i + 2][0] = min(dp[i + 2][0], big[i] + dp[i][0]);
      dp[i + 2][1] = min(dp[i + 2][1], big[i] + dp[i][1]);
    }
    // i번 돌에서 매우 큰 점프를 하는 경우
    if (i + 3 < N)
      dp[i + 3][1] = min(dp[i + 3][1], K + dp[i][0]);
  }

  cout << min(dp[N - 1][0], dp[N - 1][1]) << '\n';
}

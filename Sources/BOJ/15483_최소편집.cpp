#include <iostream>
using namespace std;

int dp[1001][1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string A, B;
  cin >> A >> B;

  int N = A.size(), M = B.size();
  for (int i = 0; i <= N; i++)
    dp[i][0] = i;
  for (int i = 0; i <= M; i++)
    dp[0][i] = i;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1); // 추가, 삭제
      dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (A[i - 1] != B[j - 1]));  // 교체
    }
  cout << dp[N][M] << '\n';
}

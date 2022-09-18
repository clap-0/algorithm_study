#include <iostream>
using namespace std;

// dp[i][j] = 1행1열부터 i행j열 범위에 거주 중인 사람 수의 총합
int dp[1025][1025];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N, M, K;
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      int population;
      cin >> population;
      dp[i][j] = population + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    }
  cin >> K;
  for (int i = 0; i < K; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
    cout << ans << '\n';
  }
}

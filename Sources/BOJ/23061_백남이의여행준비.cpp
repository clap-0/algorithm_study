#include <iostream>
using namespace std;

int w[100], v[100], k[100];
int dp[1000001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> w[i] >> v[i];

  int maxK = 0;
  for (int i = 0; i < M; i++) {
    cin >> k[i];
    maxK = max(maxK, k[i]);
  }

  // DP
  for (int i = 0; i < N; i++)
    for (int j = maxK; j >= w[i]; j--)
      dp[j] = max(dp[j], v[i] + dp[j - w[i]]);

  int ans = 1;
  double efficiency = 0; 
  for (int i = 0; i < M; i++)
    if (efficiency < 1.0 * dp[k[i]] / k[i]) {
      efficiency = 1.0 * dp[k[i]] / k[i];
      ans = i + 1;
    }
  cout << ans << '\n';
}

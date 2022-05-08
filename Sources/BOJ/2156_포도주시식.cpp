#include <iostream>
using namespace std;

int wines[10001];
int dp[10001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> wines[i];

  dp[1] = wines[1];
  dp[2] = wines[1] + wines[2];
  // (i - 3)번째와 그 이전 잔들과 (i - 1)번째 잔, i번째 잔을 마시는 경우
  // (i - 2)번째와 그 이전 잔들과 i번째 잔을 마시는 경우
  // (i - 1)번째와 그 이전 잔들만 마시고 i번째 잔은 마시지 않는 경우
  for(int i = 3; i <= n; i++)
    dp[i] = max(dp[i - 3] + wines[i - 1] + wines[i], max(dp[i - 2] + wines[i], dp[i - 1]));

  cout << dp[n] << '\n';
}

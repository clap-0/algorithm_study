#include <iostream>
using namespace std;

int dp[300001], piles[775];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N;
  cin >> N;
  
  int h = 1;
  for (; h + piles[h - 1] <= N; h++)
    piles[h] = piles[h - 1] + h;
  for (int i = 1; i < h; i++)
    piles[i] += piles[i - 1];

  for (int i = 1; i <= N; i++) {
    dp[i] = 300000;
    for (int j = 1; piles[j] <= i; j++)
      dp[i] = min(dp[i], 1 + dp[i - piles[j]]);
  }

  cout << dp[N] << '\n';
}

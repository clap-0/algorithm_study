#include <iostream>
using namespace std;

bool dp[2][7];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  dp[0][0] = true;
  for (int i = 0; i < N; i++) {
    int days;
    cin >> days;
    for (int j = 0; j < 7; j++)
      if (dp[i % 2][j]) {
        dp[(i + 1) % 2][j] = true;
        dp[(i + 1) % 2][(j + days) % 7] = true;
      }
  }

  cout << (dp[N % 2][4] ? "YES\n" : "NO\n");
}

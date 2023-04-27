#include <iostream>
using namespace std;

const int MAX_N = 10;
int dp[MAX_N + 1];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  
  dp[1] = 0;
  for (int i = 2; i <= N; i++) {
    int half1 = i / 2, half2 = half1 + (i % 2);
    dp[i] = dp[half1] + dp[half2] + half1 * half2;
  }
  cout << dp[N] << '\n';
}

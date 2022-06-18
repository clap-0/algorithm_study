#include <iostream>
using namespace std;

int dp[16];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, T, P;
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> T >> P;
    if(i + T <= N) dp[i + T] = max(dp[i + T], dp[i] + P);
    dp[i + 1] = max(dp[i + 1], dp[i]);
  }

  cout << dp[N] << '\n';
}

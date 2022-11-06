#include <iostream>
using namespace std;

int A[5000];
long long dp[5000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> A[i];
  
  for (int i = 1; i < N; i++) {
    dp[i] = (1LL + abs(A[i] - A[0])) * i;
    for (int j = 1; j < i; j++)
      dp[i] = min(dp[i], max(dp[j], (1LL + abs(A[i] - A[j])) * (i - j)));
  }

  cout << dp[N - 1] << '\n';
}

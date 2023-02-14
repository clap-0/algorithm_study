#include <iostream>
using namespace std;

const int MOD = 1e9 + 9;
int dp[100001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  dp[0] = dp[1] = 1;  // 1 = 1
  dp[2] = dp[3] = 2;  // 2 = [1+1, 2], 3 = [1+1+1, 3]
  dp[4] = dp[5] = 3;  // 4 = [1+1+1+1, 1+2+1, 2+2], 5 = [1+1+1+1+1, 1+3+1, 2+1+2]
  
  for (int i = 6; i <= 100000; i++) {
    dp[i] = dp[i - 2];  // i를 양 끝이 1인 합으로 나타내는 경우의 수 (1 + dp[i-2] + 1)
    dp[i] = (dp[i] + dp[i - 4]) % MOD;  // i를 양 끝이 2인 합으로 나타내는 경우의 수 (2 + dp[i-4] + 2)
    dp[i] = (dp[i] + dp[i - 6]) % MOD;  // i를 양 끝이 3인 합으로 나타내는 경우의 수 (3 + dp[i-6] + 3)
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }
}

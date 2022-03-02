#include <iostream>
using namespace std;

// dp[i][j] = i자리인 수 중에 3으로 나눈 나머지가 j인 수의 개수
int dp[10][3];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  dp[1][0] = 0, dp[1][1] = 1, dp[1][2] = 1;
  for(int i = 2; i <= N; i++) {
    dp[i][0] = dp[i][1] = dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
  }

  cout << dp[N][0] << '\n';
}

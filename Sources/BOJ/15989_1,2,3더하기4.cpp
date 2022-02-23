#include <iostream>
using namespace std;


// dp[i][j] = 정수 i를 만들 때 마지막으로 더한 수가 j + 1인 경우의 수
int dp[10001][3];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  // 오름차순으로만 더하는 경우만 구하도록 해 중복으로 세는 경우를 없앤다
  dp[0][0] = 1;
  for(int i = 1; i <= 10000; i++) {
    // 마지막으로 더한 수가 1인 경우, 그 전에 더한 수는 오름차순이여야 하므로 1밖에 안 된다
    dp[i][0] = dp[i - 1][0];
    // 마지막으로 더한 수가 2인 경우, 그 전에 더한 수는 1,2만 된다
    if(i >= 2) dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
    // 마지막으로 더한 수가 3인 경우, 그 전에 더한 수는 1,2,3이 된다
    if(i >= 3) dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
  }
  
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    cout << dp[n][0] + dp[n][1] + dp[n][2] << '\n';
  }
}

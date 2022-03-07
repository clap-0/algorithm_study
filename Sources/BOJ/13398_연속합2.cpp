#include <iostream>
using namespace std;

int arr[100000];
// dp[i] = arr[..i] 범위에서 { 수를 제거하지 않았을 때 연속합의 최댓값 , 수를 제거했을 때 연속합의 최댓값 }
int dp[100000][2];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];

  int ans;
  ans = dp[0][0] = arr[0];
  for(int i = 1; i < n; i++) {
    // arr[..i]에서 수를 제거하지 않는 경우
    // dp[i][0]의 값은 dp[i - 1][0]이 음수면 arr[i], 양수면 arr[i] + dp[i - 1][0]이다
    dp[i][0] = max(0, dp[i - 1][0]) + arr[i];
    
    // arr[..i]에서 수를 제거하는 경우
    // arr[i]를 제거하는 경우의 값과 범위 arr[..i)의 값을 제거했을 때의 최댓값 중 더 큰 값이다
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
    ans = max(ans, max(dp[i][0], dp[i][1]));
  }

  cout << ans << '\n';
}

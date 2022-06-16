#include <iostream>
#include <cstring>
using namespace std;

int coins[20];
int dp[10001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int N, M;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> coins[i];
    cin >> M;

    // dp[k] = 금액 k를 만드는 방법의 수
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    // 이전에 구한 금액 k를 만드는 방법의 수와 i번째 동전으로 만드는 방법의 수를 더한다
    // i번째 동전부터 순차적으로 실행하기 때문에 하나의 방법에 대해 순서만 바뀐 다른 방법이 나오지 않는다
    for(int i = 0; i < N; i++)
      for(int k = coins[i]; k <= M; k++)
        dp[k] = dp[k] + dp[k - coins[i]];
    cout << dp[M] << '\n';
  }
}

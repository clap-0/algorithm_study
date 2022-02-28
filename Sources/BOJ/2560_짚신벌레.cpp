#include <iostream>
using namespace std;

const int MOD = 1000;

// dp[i] = i일에 살아있는 짚신벌레의 수. 죽어서 사라지는 수는 고려하지 않는다
int dp[1000001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int a, b, d, N;
  cin >> a >> b >> d >> N;

  // 첫 짚신벌레를 넣은 후 a일만큼 지나기 전에는 처음 넣은 짚신벌레 한 마리만 살아있다
  for(int i = 0; i < a; i++) dp[i] = 1;

  for(int i = a; i <= N; i++) {
    // i-1일에 생존해있는 짚신벌레는 i일에도 그대로 생존해있다
    dp[i] = dp[i - 1];
    // i-a일에 생존해있는 모든 짚신벌레는 i일에 새로운 개체를 생산해낸다
    dp[i] = (dp[i] + dp[i - a]) % MOD;
    // i-b일에 생존해있는 짚신벌레들은 i일에는 더 이상 개체를 생산해내지 못한다
    if(i >= b) dp[i] = (dp[i] - dp[i - b] + MOD) % MOD;
  }

  int ans = dp[N];
  // N일이 되기 d일 전에 살아있던 모든 짚신벌레들은 N일이 되면 죽는다
  if(N >= d) ans = (ans - dp[N - d] + MOD) % MOD;

  cout << ans << '\n';
}

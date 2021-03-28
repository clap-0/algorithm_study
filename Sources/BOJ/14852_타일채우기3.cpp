#include <iostream>
using namespace std;
const int MOD = 1e9+7;
int main() {
  int n;
  int dp1[1000001], dp2[1000001];
  cin >> n;
  dp1[0] = 1; dp1[1] = 2;
  dp2[0] = 0; dp2[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp2[i] = ((dp1[i - 1] + dp1[i - 2]) % MOD + dp2[i - 2]) % MOD;
    dp1[i] = (dp1[i - 2] + (2 * dp2[i]) % MOD) % MOD;
  }
  cout << dp1[n] << endl;
  return 0;
}

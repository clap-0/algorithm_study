#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
int cache[1000001];
// DP를 이용하여 피보나치수를 구한다
// fast doubling method를 사용하여 큰 피보나치 수를 빠르게 구할 수 있게 했다
int fib(int n){
  // 메모이제이션
  int& ret = cache[n];
  if(ret!=0) return ret;
  // fib(2n+1) = fib(n+1)² + fib(n)²
  // fib(2n) = fib(n) * (2*fib(n+1) - fib(n))
  long long A=fib(n/2+1), B=fib(n/2);
  if(n&1) return ret = (A*A%MOD + B*B%MOD)%MOD;
  // 연산값이 음수가 되는 걸 방지하기 위해 MOD를 더했다
  else return ret = (2ll*A%MOD*B%MOD - B*B%MOD + MOD)%MOD;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  if(n==0) cout << 0 << '\n';
  else {
    cache[1] = cache[2] = 1;
    cout << fib(n) << '\n';
  }
}

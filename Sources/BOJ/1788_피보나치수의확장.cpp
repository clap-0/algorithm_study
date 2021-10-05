#include <iostream>
#include <cstring>
using namespace std;
const int MOD=1000000000;
int cache[1000001];
// DP를 이용하여 피보나치수를 구한다
// fast doubling method를 사용하여 큰 피보나치 수를 빠르게 구할 수 있게 했다
int fib(int n){
  // 메모이제이션
  int& ret=cache[n];
  if(ret!=-1) return ret;
  // fib(2n+1) = fib(n+1)² + fib(n)²
  // fib(2n) = fib(n) * (2*fib(n+1) - fib(n))
  long long a=fib(n/2), b=fib(n/2+1);
  if(n&1) return ret = (a*a%MOD + b*b%MOD)%MOD;
  return ret = (2ll*a%MOD*b%MOD - a*a%MOD + MOD)%MOD;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  memset(cache, -1, sizeof(cache));
  cache[1] = cache[2] = 1;
  if(n==0) cout << 0 << '\n' << 0 << '\n';
  else {
    cout << (n<0 && -n%2==0 ? -1 : 1) << '\n';
    cout << fib(abs(n)) << '\n';
  }
}

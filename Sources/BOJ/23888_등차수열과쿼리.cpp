#include <iostream>
using namespace std;

long long gcd(long long p, long long q)
{
  if (q == 0LL)
    return p;
  return gcd(q, p % q);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int a, d, q;
  cin >> a >> d >> q;
  while (q--) {
    int opt;
    long long l, r;
    cin >> opt >> l >> r;
    if (opt == 1) {
      cout << (r-l+1) * a + (r*(r-1)-(l-1)*(l-2))/2 * d << '\n';
    }
    else {
      // 등차수열의 최대공약수는 a와 d의 최대공약수
      cout << (l == r ? a + (l - 1) * d : gcd(a, d)) << '\n';
    }
  }
}

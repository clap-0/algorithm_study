#include <iostream>
#include <cmath>
using namespace std;

// 정수 p와 q의 최대공약수를 반환하는 함수
int GCD(int p, int q) {
  if(q == 0) return p;
  return GCD(q, p%q);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int gcd, lcm;
  cin >> gcd >> lcm;

  // A * B / gcd == lcm이므로
  // A * B == lcm * gcd이고, GCD(A, B) == gcd를 만족시키는 A와 B를 구한다
  int A = 1e8, B = 1e8;
  long long N = 1LL * gcd * lcm;
  int sqrtn = (int)sqrt(N);
  for(int i = gcd; i <= sqrtn; i += gcd) {
    if(N % i) continue;
    int j = N / i;
    if(GCD(i, j) == gcd && A + B > i + j) {
      A = i;
      B = j;
    }
  }

  cout << A << " " << B << '\n';
}

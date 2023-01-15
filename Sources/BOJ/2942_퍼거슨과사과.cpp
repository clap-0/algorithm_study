#include <iostream>
using namespace std;

// p와 q의 최대공약수를 구하는 알고리즘
int getGCD(int p, int q)
{
  if (q == 0)
    return p;
  return getGCD(q, p % q);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int R, G;
  cin >> R >> G;
  int gcd = getGCD(R, G);
  // gcd의 약수를 구한다.
  for (int i = 1; i * i <= gcd; i++)
    if (gcd % i == 0) {
      cout << i << ' ' << R / i << ' ' << G / i << '\n';
      if (gcd / i != i) // 4, 16, ... 같은 제곱수가 아닌 수들은 gcd / i도 출력한다.
        cout << gcd / i << ' ' << R / gcd * i << ' ' << G / gcd * i << '\n';
    }
}

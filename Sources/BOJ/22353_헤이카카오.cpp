#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int a;
  double d, k;
  cin >> a >> d >> k;
  d /= 100.0; k /= 100.0;

  int minutes = a;
  // expectedValue = 기댓값
  // prevLostProbability = 이전 끝말잇기를 모두 질 확률
  double expectedValue = 0.0, prevLostProbability = 1.0;
  while(d < 1) {
    expectedValue += minutes * prevLostProbability * d;
    prevLostProbability *= (1 - d);
    d += d * k;
    minutes += a;
  }
  expectedValue += minutes * prevLostProbability;

  cout << fixed;
  cout.precision(6);
  cout << expectedValue << '\n';
}

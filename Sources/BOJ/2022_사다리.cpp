#include <iostream>
#include <cmath>
using namespace std;

double x, y, c;

double func(double z) {
  double A = sqrt(x*x - z*z), B = sqrt(y*y - z*z);
  return A*B / (A+B);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> x >> y >> c;

  // 이분탐색 알고리즘. 정해진 횟수만큼 반복하여 값을 구한다
  double lo = 0, hi = min(x, y);
  for(int i=0; i<100; i++) {
    double mid = (lo + hi) / 2.0;
    if(func(mid) >= c) lo = mid;
    else hi = mid;
  }
  cout << fixed;
  cout.precision(3);
  cout << lo << '\n';
}

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int X, Y, D, T;
  cin >> X >> Y >> D >> T;

  double d = sqrt(pow(X, 2) + pow(Y, 2));
  double ans = d; // 걸어서 집까지 가는 경우
  
  int cnt = (int)(d / D);
  ans = min(ans, cnt * (T - D) + d);  // 일직선 상으로 집 이전까지 점프하다가 나머지는 걸어가는 경우
  ans = min(ans, (cnt + 1) * (T + D) - d);  // 일직선 상으로 집을 넘어서까지 점프하다가 집까지 되돌아서 걸어가는 경우

  int c = max(2, (int)ceil(d / D));
  ans = min(ans, (double)c * T);  // 일직선 상으로 점프해서 가다가 남은 거리가 밑변이 되는 이등변삼각형 모양으로 점프하는 경우
  
  cout << fixed;
  cout.precision(9);
  cout << ans << '\n';
}

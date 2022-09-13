#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N, L, W, H;
  cin >> N >> L >> W >> H;

  double lo = 0.0, hi = min(min(L, W), H);
  double ans = -1.0;
  int cnt = 0;  // lo와 hi가 실수이므로 while문에 넣었을 때 오차가 발생할 수 있어서 단순히 while문을 100번 수행하도록 했다.
  while (cnt++ < 100) {
    double mid = (lo + hi) / 2.0;
    // capacity : 한 변의 길이가 mid인 정육면체를 L*W*H 크기의 직육면체에 넣을 수 있는 갯수
    long long capacity = (long long)(L / mid) * (long long)(W / mid) * (long long)(H / mid);
    if (capacity < N)
      hi = mid;
    else {
      lo = mid;
      ans = mid;
    }
  }

  cout << fixed;
  cout.precision(9);
  cout << ans << '\n';
}

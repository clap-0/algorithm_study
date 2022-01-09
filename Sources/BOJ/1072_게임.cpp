#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int X, Y, Z;
  cin >> X >> Y;
  Z = 100LL * Y / X;
  
  // 확률이 99%이상인 경우 게임을 얼마나 더 하든 확률이 변하지 않는다
  if(Z >= 99) {
    cout << -1 << '\n';
    return 0;
  }
  
  long long lo = 1, hi = X;
  int ans;
  while(lo <= hi) {
    long long mid = (lo + hi) / 2;
    if(100LL * (Y + mid) / (X + mid) == Z) lo = mid + 1;
    else {
      hi = mid -1;
      ans = mid;
    }
  }
  cout << ans << '\n';
}

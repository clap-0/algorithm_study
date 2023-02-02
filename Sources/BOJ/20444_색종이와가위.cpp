#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  long long k;
  cin >> n >> k;

  // 가로로 자르는 횟수를 이분 탐색으로 바꾸어가며
  // k조각으로 만들 수 있는지 확인한다.
  bool ans = false;
  int lo = 0, hi = n / 2;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    // 종이 조각의 수 = (가로로 자른 횟수 + 1) * (세로로 자른 횟수 + 1)
    long long pieces = (mid + 1LL) * (n - mid + 1LL);
    if (pieces < k) lo = mid + 1;
    else if (pieces > k) hi = mid - 1;
    else {
      ans = true;
      break;
    }
  }

  cout << (ans ? "YES\n" : "NO\n");
}

#include <iostream>
using namespace std;

int N, K;
int x[100000];

// 각각의 그룹에서 맞은 문제 개수의 합들 중 최솟값이
// m이 되도록 하는 그룹의 수의 최댓값
int countGroups(int m)
{
  int ret = 0;
  int sum = 0;
  for (int i = 0; i < N; i++)
    if ((sum += x[i]) >= m) {
      ++ret;
      sum = 0;
    }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> K;
  int lo = 0, hi = 0;
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    hi += x[i];
  }
  
  int ans;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    // 각각의 그룹에서 맞은 문제 개수의 합들 중 최솟값이
    // mid가 되도록 하는 그룹의 수가 K개 이상이면
    // mid를 늘려가며 최댓값을 구한다.
    if (countGroups(mid) >= K) {
      ans = mid;
      lo = mid + 1;
    }
    else
      hi = mid - 1;
  }
  
  cout << ans << '\n';
}

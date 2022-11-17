#include <iostream>
#include <algorithm>
using namespace std;

int growthPeriod[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> growthPeriod[i];

  // 나무가 다 자라는데 걸리는 시간에 대해 내림차순 정렬
  sort(growthPeriod, growthPeriod + n, greater<int>());

  int ans = -1;
  for (int i = 0; i < n; i++)
    ans = max(ans, i + 2 + growthPeriod[i]);
  cout << ans << '\n';
}

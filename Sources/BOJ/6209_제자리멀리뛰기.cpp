#include <iostream>
#include <algorithm>
using namespace std;

int d, n, m;
int dist[50001];

// m개 이하의 돌을 제거했을 때, 점프하는 최소 거리가 minDist 이상인가?
bool isValid(int minDist)
{
  int cnt = 0;
  int tmp = 0;
  for (int i = 0; i <= n; i++)
    if (minDist > dist[i] - tmp)
      ++cnt;
    else
      tmp = dist[i];
  
  return cnt <= m;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> d >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> dist[i];
  
  sort(dist, dist + n);
  dist[n] = d;

  int ans;
  int lo = 1, hi = d;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (isValid(mid)) {
      ans = mid;
      lo = mid + 1;
    }
    else
      hi = mid - 1;
  }

  cout << ans << '\n';
}

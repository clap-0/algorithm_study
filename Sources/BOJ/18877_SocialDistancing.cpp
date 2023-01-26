#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
pair<long long,long long> grass[100000];

// 소들 사이의 거리를 D 이상으로 하여
// N 마리의 소들이 거리두기할 수 있는지 반환
bool canSpreadMoreThan(long long D)
{
  long long cnt = 0LL;
  long long left = 0LL, tmp;
  for (int i = 0; i < M; i++) 
    if (left <= grass[i].second) {
      left = max(left, grass[i].first);
      tmp = 1LL + (grass[i].second - left) / D;
      cnt += tmp;
      left += tmp * D;
    }
  return N <= cnt;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  long long maxEndPoint = 0LL;
  for (int i = 0; i < M; i++) {
    cin >> grass[i].first >> grass[i].second;
    maxEndPoint = max(grass[i].second, maxEndPoint);
  }
  sort(grass, grass + M);

  long long ans;
  long long lo = 1LL, hi = maxEndPoint / (N - 1);
  while (lo <= hi) {
    long long mid = (lo + hi) / 2LL;
    if (canSpreadMoreThan(mid)) {
      ans = mid;
      lo = mid + 1LL;
    }
    else
      hi = mid - 1LL;
  }

  cout << ans << '\n';
}

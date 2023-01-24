#include <iostream>
#include <algorithm>
using namespace std;

int N, M, L;
int pos[51];

// 휴게소가 없는 구간의 최댓값이 interval이 되도록 하기 위해
// 세워야 하는 휴게소의 개수를 반환하는 함수
int countServiceArea(int interval)
{
  int ret = 0;
  for (int i = 0; i <= N; i++)
    ret += (pos[i] - 1) / interval;
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M >> L;
  for (int i = 0; i < N; i++)
    cin >> pos[i];
  // 마지막 휴게소와 고속도로의 끝 사이의 구간도 고려하기 위해
  // 고속도로 끝의 위치도 넣는다.
  pos[N] = L;

  // 인접한 두 휴게소 사이의 구간의 길이를 구한다.
  sort(pos, pos + N);
  for (int i = N; i > 0; i--)
    pos[i] -= pos[i - 1];

  // 이분탐색을 통해 휴게소가 없는 구간의 최댓값의 최솟값을 구한다.
  int ans;
  int lo = pos[0], hi = L;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    // 휴게소가 없는 구간의 최댓값이 mid가 되도록 할 때
    // 세워야 하는 휴게소의 개수가 M 이하인 경우
    // mid를 줄여나가며 최솟값을 구한다.
    if (countServiceArea(mid) <= M) {
      ans = mid;
      hi = mid - 1;
    }
    else
      lo = mid + 1;
  }

  cout << ans << '\n';
}

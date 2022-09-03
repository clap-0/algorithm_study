#include <iostream>
#include <algorithm>
using namespace std;

int M, N, L;
int guns[100000]; // 사대의 위치. 오름차순으로 정렬한다.

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> M >> N >> L;
  for (int i = 0; i < M; i++)
    cin >> guns[i];
  // 사대의 위치 오름차순 정렬
  sort(guns, guns + M);
  
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    // upper : 동물 위치의 x좌표값보다 좌표가 큰 사대들 중 좌표가 가장 작은 사대의 인덱스값
    int upper = upper_bound(guns, guns + M, x) - guns;
    // lower : 동물 위치의 x좌표값보다 좌표가 작거나 같은 사대들 중 좌표가 가장 큰 사대의 인덱스값
    int lower = max(0, upper - 1);
    upper = min(M - 1, upper);  // 동물의 x좌표가 가장 오른쪽에 있는 사대보다 더 크거나 같은 경우, upper를 M-1로 한다.
    // dist : 동물과 가장 가까운 사대와의 거리
    int dist = min(abs(x - guns[lower]), abs(x - guns[upper])) + y;
    if (dist <= L)
      ++ans;
  }
  cout << ans << '\n';
}

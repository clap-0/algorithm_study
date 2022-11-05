#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
int field[501][501];
int cost[501][501];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  for (int k = 1; k >= -1; k -= 2) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      // x1 < x2, y1 < y2를 항상 만족하게 한다.
      if (x1 > x2)
        swap(x1, x2);
      if (y1 > y2)
        swap(y1, y2);
      for (int y = y1; y <= y2; y++)
        for (int x = x1; x <= x2; x++)
          field[y][x] = k;
    }
  }

  // 데이크스트라 알고리즘
  fill((int*)cost, (int*)(cost + 501), 987654321);
  cost[0][0] = 0;
  priority_queue<pair<int,pair<int,int> > > pq;
  pq.push({0, {0, 0}});
  while (!pq.empty()) {
    int c = -pq.top().first, y = pq.top().second.first, x = pq.top().second.second;
    pq.pop();
    // 목적지에 도착한 경우 break
    if (y == 500 && x == 500)
      break;
    // c보다 더 나은 비용을 찾아낸 경우, 패스
    if (cost[y][x] < c)
      continue;
    
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny > 500 || nx > 500 || field[ny][nx] == -1)
        continue;
      if (cost[ny][nx] > cost[y][x] + field[ny][nx]) {
        cost[ny][nx] = cost[y][x] + field[ny][nx];
        pq.push({-cost[ny][nx], {ny, nx}});
      }
    }
    field[y][x] = -1;
  }

  cout << (cost[500][500] != 987654321 ? cost[500][500] : -1) << '\n';
}

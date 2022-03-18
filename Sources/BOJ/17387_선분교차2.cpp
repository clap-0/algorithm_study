#include <iostream>
using namespace std;

typedef pair<int,int> pii;

// 점의 좌표 a, b, c가 주어질 때, 선분 ab와 점 c간의 위치관계를 벡터의 외적을 이용하여 구한다
int getLocation(pii a, pii b, pii c) {
  long long ret;
  pii u = {b.first - a.first, b.second - a.second};
  pii v = {c.first - a.first, c.second - a.second};
  ret = 1LL * u.first * v.second - 1LL * u.second * v.first;
  return (ret > 0 ? 1 : (ret < 0 ? -1 : 0));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  pair<int,int> p[4];
  for(int i = 0; i < 2; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    p[i * 2] = {x1, y1}, p[i * 2 + 1] = {x2, y2};
  }

  // 한 선분을 기준으로 다른 선분의 양 끝점이 각각 시계방향, 반시계방향에 있는지 구한다
  // 양수면 두 점이 같은 방향에, 음수면 다른 방향에, 0이면 둘 중 한 점이 일직선 상에 있음
  int loc1 = getLocation(p[0], p[1], p[2]) * getLocation(p[0], p[1], p[3]);
  int loc2 = getLocation(p[2], p[3], p[0]) * getLocation(p[2], p[3], p[1]);

  if(loc1 == 0 && loc2 == 0) {
    if(p[0] > p[1]) swap(p[0], p[1]);
    if(p[2] > p[3]) swap(p[2], p[3]);
    if(p[2] <= p[1] && p[0] <= p[3]) cout << 1 << '\n';
    else cout << 0 << '\n';
  }
  else if(loc1 <= 0 && loc2 <= 0) cout << 1 << '\n';
  else cout << 0 << '\n';
}

#include <iostream>
using namespace std;

// 선분에 대한 구조체
struct Line {
  int x1, y1, x2, y2;
  // u : 점 (x1,y1)에서 점 (x2,y2)로의 벡터
  pair<int,int> u;
  Line() : Line(0, 0, 0, 0) {}
  Line(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d) {
    u = {c - a, d - b};
  }
};

// 선분 L과 점 (x,y)간의 위치관계를 벡터의 외적을 이용하여 구한다
int getLocation(Line& L, int x, int y) {
  long long ret = 1LL;
  pair<int,int> v;
  v = {x - L.x1, y - L.y1};
  ret *= 1LL * L.u.first * v.second - 1LL * L.u.second * v.first;
  return (ret > 0 ? 1 : (ret < 0 ? -1 : 0));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  Line L[2];
  for(int i = 0; i < 2; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    L[i] = Line(x1, y1, x2, y2);
  }

  // 한 선분을 기준으로 다른 선분의 양 끝점이 각각 시계방향, 반시계방향에 있는지 구한다
  // 양수면 두 점이 같은 방향에, 음수면 다른 방향에, 0이면 둘 중 한 점이 일직선 상에 있음
  int loc1 = getLocation(L[0], L[1].x1, L[1].y1) * getLocation(L[0], L[1].x2, L[1].y2);
  int loc2 = getLocation(L[1], L[0].x1, L[0].y1) * getLocation(L[1], L[0].x2, L[0].y2);

  if(loc1 <= 0 && loc2 <= 0) cout << 1 << '\n';
  else cout << 0 << '\n';
}

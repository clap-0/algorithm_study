#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

pll P[4];

// 선분 AB를 기준으로 점 C의 위치가 반시계방향이면 1, 시계방향이면 -1, 일직선상이면 0을 반환한다
int ccw(const pll& A, const pll& B, const pll& C) {
  ll outerProduct = (B.first - A.first) * (C.second - A.second) - (B.second - A.second) * (C.first - A.first);
  return (outerProduct > 0 ? 1 : (outerProduct < 0 ? -1 : 0));
}

// 선분 AB를 기준으로 한 점C와 D의 위치관계 loc1과
// 선분 CD를 기준으로 한 점A와 B의 위치관계 loc2가 주어질 때
// 선분 AB와 CD가 교차하는지 여부를 반환한다
bool crossCheck(const int loc1, const int loc2) {
  // 두 선분이 한 끝점에서 만나거나 일직선상에 있는 경우
  if(loc1 == 0 && loc2 == 0) {
    if(P[0] > P[1]) swap(P[0], P[1]);
    if(P[2] > P[3]) swap(P[2], P[3]);
    if(P[0] <= P[3] && P[2] <= P[1]) return true; // 두 선분이 한 끝점에서 만나거나 겹쳐있다
    return false; // 두 선분이 일직선상에 있지만 만나지 않는다
  }
  // 두 선분이 한 점에서 교차하거나 만나는 경우
  else if(loc1 <= 0 && loc2 <= 0) return true;
  else return false;
}

// 교차점의 좌표를 출력한다
void getCrossPoint() {
  // 선분 AB와 CD의 교차점의 좌표 : cross = ((A.x, A.y, 1) x (B.x, B.y, 1)) x ((C.x, C.y, 1) x (D.x, D.y, 1))에 대하여 (cross.x / cross.z, cross.y / cross.z)
  double u[3] = {P[0].second - P[1].second, P[1].first - P[0].first, P[0].first * P[1].second - P[0].second * P[1].first};
  double v[3] = {P[2].second - P[3].second, P[3].first - P[2].first, P[2].first * P[3].second - P[2].second * P[3].first};
  double cross[3] = {u[1]*v[2] - u[2]*v[1], u[2]*v[0] - u[0]*v[2], u[0]*v[1] - u[1]*v[0]};
  
  // 선분 AB와 CD가 일직선상에 있지 않은 경우
  if(cross[2] != 0) {
    cout << fixed;
    cout.precision(9);
    cout << cross[0] / cross[2] << ' ' << cross[1] / cross[2] << '\n';
    return;
  }

  // 선분 AB와 CD가 일직선상에 있는 경우 끝점에서 만나는 경우에만 출력한다
  if(P[0] == P[3]) cout << P[0].first << ' ' << P[0].second << '\n';
  else if(P[1] == P[2]) cout << P[1].first << ' ' << P[1].second << '\n';
}

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  for(int i = 0; i < 4; i++) cin >> P[i].first >> P[i].second;

  bool isCrossed = crossCheck(ccw(P[0], P[1], P[2]) * ccw(P[0], P[1], P[3]), ccw(P[2], P[3], P[0]) * ccw(P[2], P[3], P[1]));
  
  cout << isCrossed << '\n';
  if(isCrossed) {
    getCrossPoint();
  }
}

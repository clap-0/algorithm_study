#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  pair<int,int> P[3];
  for(int i = 0; i < 3; i++) cin >> P[i].first >> P[i].second;
  
  // 벡터 P₁P₂와 벡터 P₁P₃를 구한다
  pair<int,int> P1P2 = {P[1].first - P[0].first, P[1].second - P[0].second};
  pair<int,int> P1P3 = {P[2].first - P[0].first, P[2].second - P[0].second};
  
  // 벡터 P₁P₂와 벡터 P₁P₃의 외적이 양수면 CCW(반시계), 음수면 CW(시계), 0이면 일직선이다
  int cross = P1P2.first * P1P3.second - P1P2.second * P1P3.first;
  cout << (cross > 0 ? 1 : (cross < 0 ? -1 : 0)) << '\n';
}

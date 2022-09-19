#include <iostream>
using namespace std;

// 중점이 center이고 반지름의 길이가 radius인 원 내부에 점 point가 있는지 여부를 반환하는 함수
bool isLocatedInCircle(const pair<int,int>& center, const int& radius, const pair<int,int>& point)
{
  // dist = (center와 point 사이의 거리)^2
  double dist = (center.first - point.first) * (center.first - point.first) + (center.second - point.second) * (center.second - point.second);
  // 두 점 사이의 거리가 반지름보다 짧으면 true, 아니면 false 반환
  if (dist < radius * radius)
    return true;
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int T;
  cin >> T;
  while (T--) {
    int n;
    // startPoint = 출발점, endPoint = 도착점
    pair<int,int> startPoint, endPoint;
    cin >> startPoint.first >> startPoint.second >> endPoint.first >> endPoint.second >> n;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
      pair<int,int> center;
      int radius;
      cin >> center.first >> center.second >> radius;
      // 주어진 원 내부에 출발점과 도착점 중 하나만 위치해있는 경우, 행성계 진입/이탈 횟수를 증가시킨다.
      if (isLocatedInCircle(center, radius, startPoint) ^ isLocatedInCircle(center, radius, endPoint))
        ++ans;
    }
    
    cout << ans << '\n';
  }
}

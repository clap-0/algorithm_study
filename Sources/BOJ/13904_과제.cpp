#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> homework[1000];
bool isAssigned[1001];

int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) 
    cin >> homework[i].first >> homework[i].second;
  
  // 과제점수에 대해 내림차순 정렬하고, 점수가 같을 경우 남은 기한에 대해 오름차순 정렬한다.
  sort(homework, homework + N, [](pair<int,int>& a, pair<int,int>& b) {
    if (a.second != b.second)
      return a.second > b.second;
    return a.first < b.first;
  });

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int d = homework[i].first;
    // d 이하의 날들 중에 아직 과제하기로 예정되지 않은 가장 먼 날에 과제를 할당한다.
    while (d > 0 && isAssigned[d])
      --d;
    if (d) {
      isAssigned[d] = true;
      ans += homework[i].second;
    }
  }
  cout << ans << '\n';
}

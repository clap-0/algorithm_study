#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> period;

// 각 꽃들의 개화기간
period flowers[100000];

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // 날짜를 month * 100 + day 로 표현
    flowers[i] = {a*100+b, c*100+d};
  }

  sort(flowers, flowers + N, [](period& a, period& b) {
    // 개화일에 대해 오름차순으로 정렬한다.
    if (a.first != b.first)
      return a.first < b.first;
    // 개화일이 같은 경우, 개화기간이 긴 꽃이 우선순위가 높으므로
    // 낙화일에 대해 내림차순으로 정렬한다.
    return a.second > b.second;
  });

  int ans = 0;
  // fallenDate = 현재까지 탐색한 꽃들의 낙화일 중 가장 마지막 낙화일을 저장한다.
  // 3월1일부터 꽃이 있어야하므로 301로 초기화한다.
  int fallenDate = 301, prevDate = 0;
  const int endDate = 1201;
  for (int i = 0; i < N && fallenDate < endDate; i++) {
    if (flowers[i].first <= prevDate && flowers[i].second >= fallenDate) {
      fallenDate = flowers[i].second;
    }
    else if (flowers[i].first <= fallenDate && flowers[i].second > fallenDate) {
      prevDate = fallenDate;
      fallenDate = flowers[i].second;
      ++ans;
    }
  }

  cout << (fallenDate >= endDate ? ans : 0) << '\n';
}

#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> task[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> task[i].first >> task[i].second;
  
  // 마감시간에 대하여 내림차순으로 정렬
  sort(task, task + n, [](pair<int,int> &a, pair<int,int> &b) {
    if (a.second != b.second)
      return a.second > b.second;
    return a.first > b.first;
  });

  // 마감시간이 가장 늦은 일부터 역순으로 시간을 할당했을 때
  // 마감시간이 가장 빠른 일을 시작하는 시간이 미룰 수 있는 마지노선이다.
  int time = task[0].second;
  for (int i = 0; i < n; i++) {
    time = min(time, task[i].second);
    time -= task[i].first;
  }

  // time이 음수면 제시간 안에 일을 끝낼 수 없다.
  cout << max(time, -1) << '\n';
}

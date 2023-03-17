#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 시작 상태에서 어떤 상태로 만들기 위해 필요한 뒤집기 횟수를
// {해당 상태, 뒤집기 횟수} 쌍으로 저장한다.
unordered_map<string, int> reverseCount;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N, K;
  cin >> N >> K;
  
  // BFS에서 상태 공간을 구현하기 쉽도록 하기 위해 순열을 문자열로 표현한다.
  string start = "", goal;
  for (int i = 1; i <= N; i++) {
    char num;
    cin >> num;
    start += num;
  }
  goal = start;
  sort(goal.begin(), goal.end());

  // BFS
  queue<pair<string, int> > Q;
  Q.push({start, 0});
  reverseCount.insert({start, 0});

  while (!Q.empty()) {
    string curr = Q.front().first;
    int count = Q.front().second;
    Q.pop();

    if (curr == goal) {
      break;
    }

    for (int i = 0; i + K <= N; i++) {
      string next = curr;
      reverse(next.begin() + i, next.begin() + i + K);
      
      // next가 현재까지 만들지 못했던 상태인 경우에만 큐에 넣는다.
      if (reverseCount.find(next) == reverseCount.end()) {
        reverseCount.insert({next, count + 1});
        Q.push({next, count + 1});
      }
    }
  }

  int ans = -1; // 시작 상태에서 오름차순으로 만들 수 없으면 -1
  if (reverseCount.find(goal) != reverseCount.end()) {
    ans = reverseCount[goal];
  }

  cout << ans << '\n';
}

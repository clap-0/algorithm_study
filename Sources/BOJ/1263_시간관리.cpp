#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> tasks[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> tasks[i].first >> tasks[i].second;
  
  sort(tasks, tasks + N, [](pair<int,int>& a, pair<int,int>& b) {
    if (a.second != b.second)
      return a.second > b.second;
    return a.first < b.first;
  });

  int ans = 1000000;
  for (int i = 0; i < N; i++) {
    ans = min(ans, tasks[i].second);
    ans -= tasks[i].first;
  }

  cout << (ans >= 0 ? ans : -1) << '\n';
}

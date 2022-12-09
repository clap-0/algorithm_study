#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int> tasks[1000];
vector<int> rows;

int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> tasks[i].first >> tasks[i].second;
  
  sort(tasks, tasks + N, [](const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first != b.first)
      return a.first < b.first;
    return a.second > b.second;
  });

  int ans = 0;
  int L = 0, R = -1;
  for (int i = 0; i < N; i++) {
    if (R + 1 < tasks[i].first) {
      ans += (R - L + 1) * rows.size();
      L = tasks[i].first;
      rows.clear();
    }
    bool isFilled = false;
    for (int& row : rows)
      if (row < tasks[i].first) {
        row = tasks[i].second;
        isFilled = true;
        break;
      }
    if (!isFilled)
      rows.push_back(tasks[i].second);
    R = max(R, tasks[i].second);
  }
  ans += (R - L + 1) * rows.size();

  cout << ans << '\n';
}

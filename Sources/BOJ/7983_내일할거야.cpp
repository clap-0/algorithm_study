#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> tasks[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> tasks[i].first >> tasks[i].second;

  sort(tasks, tasks + n, [](pair<int,int> &a, pair<int,int> &b){
    return a.second > b.second;
  });

  int ans = tasks[0].second;
  for (int i = 0; i < n; i++) {
    ans = min(ans, tasks[i].second);
    ans -= tasks[i].first;
  }

  cout << ans << '\n';
}

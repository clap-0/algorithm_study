#include <iostream>
#include <queue>
using namespace std;

int adj[1000][1000];  // 인접행렬
bool visited[1000]; // 각 정점의 방문여부

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> adj[i][j];

  // 프림 알고리즘
  long long ans = 0;
  int cnt = 0;
  priority_queue<pair<int,int> > pq;
  pq.push({0, 0});
  while (cnt <= n - 1) {
    int cost = -pq.top().first, here = pq.top().second;
    pq.pop();
    if (visited[here])
      continue;
    visited[here] = true;
    ans += cost;
    ++cnt;
    for (int there = 0; there < n; there++)
      if (!visited[there])
        pq.push({-adj[here][there], there});
  }
  cout << ans << '\n';
}

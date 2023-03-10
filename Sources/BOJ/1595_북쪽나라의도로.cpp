#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans;
vector<pair<int,int> > adj[10001];
bool visited[10001];

int dfs(int here)
{
  visited[here] = true;
  vector<int> dists = {0, 0};
  for (auto &road : adj[here]) {
    int there = road.first;
    if (!visited[there]) {
      int dist = road.second + dfs(there);
      dists.push_back(dist);
    }
  }

  sort(dists.begin(), dists.end(), greater<int>());
  ans = max(ans, dists[0] + dists[1]);
  return dists[0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

  int u, v, w;
  while (cin >> u >> v >> w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dfs(1);
  cout << ans << '\n';
}

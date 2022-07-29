#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int uf[100001];
vector<pair<int, pair<int,int> > > adj;
vector<pair<int,int> > tree[100001];
int cost[100001];

int find(int n)
{
  if(uf[n] < 0)
    return n;
  return uf[n] = find(uf[n]);
}

bool merge(int u, int v)
{
  u = find(u);
  v = find(v);
  if(u == v)
    return false;
  uf[v] = u;
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  memset(uf, -1, sizeof(uf));
  int N, M, S, E;
  cin >> N >> M >> S >> E;
  for(int i = 0; i < M; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj.push_back({w, {u, v}});
  }

  sort(adj.begin(), adj.end(), [](auto &a, auto &b){
    return a.first > b.first;
  });

  int cnt = 0;
  for(int i = 0; i < M; i++)
    if(merge(adj[i].second.first, adj[i].second.second))
    {
      tree[adj[i].second.first].push_back({adj[i].second.second, adj[i].first});
      tree[adj[i].second.second].push_back({adj[i].second.first, adj[i].first});
      if(++cnt == N - 1)
        break;
    }

  queue<int> Q;
  Q.push(S);
  cost[S] = 987654321;
  while(!Q.empty() && cost[E] == 0)
  {
    int curr = Q.front();
    Q.pop();
    for(auto &p : tree[curr])
      if(!cost[p.first])
      {
        cost[p.first] = min(cost[curr], p.second);
        Q.push(p.first);
      }
  }

  cout << cost[E] << '\n';
}

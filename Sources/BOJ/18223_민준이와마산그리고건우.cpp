#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V, E, P;
vector<pair<int,int> > adj[5001];
int dist[5001];

// 정점 S에서 나머지 정점들로 가는 각각의 최단경로를 계산한다.
void dijkstra(int S)
{
  priority_queue<pair<int,int> > pq;
  fill(dist, dist + V + 1, 987654321);
  pq.push({0, S});
  dist[S] = 0;
  
  while (!pq.empty()) {
    int cost = -pq.top().first, here = pq.top().second;
    pq.pop();
    
    if (dist[here] < cost)
      continue;
    
    for (const auto &p : adj[here]) {
      int nextCost = cost + p.second, there = p.first;
      if (dist[there] > nextCost) {
        pq.push({-nextCost, there});
        dist[there] = nextCost;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> V >> E >> P;
  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dijkstra(1);
  int shortestToV = dist[V];  // 1번정점에서 V번정점으로의 최단경로
  dijkstra(P);
  int shortestViaP = dist[1] + dist[V]; // 1번정점에서 P번정점을 거쳐 V번정점으로 가는 최단경로

  cout << (shortestToV == shortestViaP ? "SAVE HIM\n" : "GOOD BYE\n");
}

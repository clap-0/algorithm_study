#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v, e, k;
const int MAX_V=20001, INF=999999;
vector<pair<int, int> > adj[MAX_V]; //인접리스트. (연결된 정점번호, 간선가중치)쌍 저장
vector<int> dijkstra(int src) //다익스트라 알고리즘
{
  vector<int> dist(v+1, INF);
  dist[src]=0;
  priority_queue<pair<int, int> > pq; //(src에서 해당 정점까지 최단경로, 정점번호)
  pq.push({0, src});
  while(!pq.empty()){
    pair<int, int> t = pq.top();
    pq.pop();
    int cost = -t.first, here = t.second;
    if(dist[here] < cost) continue; //지금 꺼낸 것보다 더 짧은 경로를 알고있다면 무시
    for(auto next : adj[here]){
      int there = next.first;
      int nextDist = next.second + cost;
      if(dist[there] > nextDist){ //더 짧은 경로 발견시 최신화시키고 우선순위큐에 넣기
        dist[there] = nextDist;
        pq.push({-nextDist, there});
      }
    }
  }
  return dist;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> v >> e >> k;
  for(int i=0; i<e; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  vector<int> dist = dijkstra(k);
  for(int i=1; i<=v; i++)
    if(dist[i]!=INF) cout << dist[i] << '\n';
    else cout << "INF\n";
  return 0;
}

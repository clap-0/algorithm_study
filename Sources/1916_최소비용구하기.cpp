#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V = 1001, INF = 987654321;
int n, m;
vector<pair<int, int> > adj[MAX_V]; //인접리스트. (연결된 정점번호, 간선 가중치)쌍 저장
vector<int> dijkstra(int src){
  vector<int> dist(n+1, INF);
  dist[src]=0;
  priority_queue<pair<int, int> > pq;
  pq.push({0, src});
  while(!pq.empty()){
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();
    if(dist[here] < cost) continue; //꺼낸 것보다 더 짧은 경로를 알면 무시
    for(auto &p : adj[here]){
      int there = p.first;
      int nextDist = cost + p.second;
      if(dist[there] > nextDist){ //더 짧은 경로 발견하면 dist[] 최신화, 우선순위큐에 
        dist[there]=nextDist;
        pq.push({-nextDist, there}); //거리가 짧은 정점순으로 꺼내기위해 음수로 넣음
      }
    }
  }
  return dist;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  int start, end;
  cin >> start >> end;
  vector<int> dist = dijkstra(start);
  cout << dist[end] << endl;
  return 0;
}

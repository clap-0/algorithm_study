#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V=801, INF=987654321;
int n, e, v1, v2;
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
    if(dist[here] < cost) continue;
    for(auto &p : adj[here]){
      int there = p.first;
      int nextDist = cost + p.second;
      if(dist[there] > nextDist){
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
  cin.tie(NULL); cout.tie(NULL);
  cin >> n >> e;
  for(int i=0; i<e; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  cin >> v1 >> v2;
  // v1, v2를 반드시 거치는 최단경로는 1 -> v1 -> v2 -> n 과 1 -> v2 -> v1 -> n 중 짧은 거
  vector<int> distFrm1=dijkstra(1), distFrmV1=dijkstra(v1), distFrmV2=dijkstra(v2);
  int path1 = distFrm1[v1]+distFrmV1[v2]+distFrmV2[n];
  if(path1>=INF||path1<0) path1=INF;
  int path2 = distFrm1[v2]+distFrmV2[v1]+distFrmV1[n];
  if(path2>=INF||path2<0) path2=INF;
  cout << ((path1==INF&&path2==INF) ? -1 : min(path1, path2)) << endl;
  return 0;
}

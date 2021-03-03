#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, x;
const int MAX_N=1001, INF=987654321;
vector<pair<int, int> > adj[MAX_N]; // (연결된 정점번호, 간선 가중치)쌍 저장
vector<int> dijkstra(int src){ //다익스트라 알고리즘
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
  cin >> n >> m >> x;
  for(int i=0; i<m; i++){
    int u, v, t;
    cin >> u >> v >> t;
    adj[u].push_back({v, t});
  }
  vector<int> time = dijkstra(x); //x번마을에서 다른 모든 마을로 가는 최단시간에
  for(int i=1; i<=n; i++) //다른 모든 마을에서 x번마을로 가는 최단시간 더하기
    time[i] += dijkstra(i)[x];
  cout << *max_element(time.begin()+1, time.end()) << endl; //가장 오래걸리는 소요시간 출력(0번에는 INF들어갔으므로 제외)
  return 0;
}

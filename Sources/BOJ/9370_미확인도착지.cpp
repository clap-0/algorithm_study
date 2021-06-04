#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

const int MAX=2001, INF=987654321;

vector<pair<int,int> > adj[MAX];
//다익스트라 알고리즘
vector<int> dijkstra(int src){
  vector<int> dist(MAX, INF); //src에서 각 정점까지의 거리
  bool visited[MAX]={false};
  priority_queue<pair<int,int> > pq;
  pq.push({0, src});
  dist[src]=0;
  while(!pq.empty()){
    int here;
    do{
      here = pq.top().second;
      pq.pop();
    }while(!pq.empty() && visited[here]); //한번 방문했던 정점은 패스
    if(visited[here]) break; //더이상 방문할 정점이 없는 경우 종료
    visited[here]=true;
    for(auto &p : adj[here]){
      int there = p.first, cost = p.second;
      if(dist[there]>dist[here]+cost){
        dist[there]=dist[here]+cost;
        pq.push({-dist[there], there});
      }
    }
  }
  return dist;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int tc;
  cin >> tc;
  while(tc--){
    int n, m, t, s, g, h;
    cin >> n >> m >> t;
    for(int i=1; i<=n; i++){
      adj[i].clear();
    }
    cin >> s >> g >> h;
    for(int i=0; i<m; i++){
      int a, b, d;
      cin >> a >> b >> d;
      adj[a].push_back({b,d});
      adj[b].push_back({a,d});
    }
    //출발점에서 목적지후보까지의 최단거리와 교차로를 지난 후 최단거리 비교
    vector<int> distS = dijkstra(s);
    int crossroad = distS[g]>distS[h] ? g : h;
    vector<int> distCrossroad = dijkstra(crossroad);
    set<int> destination;
    for(int i=0; i<t; i++){
      int x;
      cin >> x;
      if(distS[x]==distCrossroad[x]+distS[crossroad]) destination.insert(x);
    }
    for(int d : destination) cout << d << ' ';
    cout << '\n';
  }
}

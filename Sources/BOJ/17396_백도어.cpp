#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N=100000;
const long long INF=1e11;

vector<pair<int,int> > adj[MAX_N];
vector<long long> dist(MAX_N, INF);

int main()
{
  int n, m;
  bool a[MAX_N];
  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<m; i++){
    int a, b, t;
    cin >> a >> b >> t;
    adj[a].push_back({b,t});
    adj[b].push_back({a,t});
  }
  //다익스트라 알고리즘
  priority_queue<pair<long long,int> > pq;
  pq.push({0, 0});
  dist[0]=0;
  while(!pq.empty()){
    long long cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();
    if(dist[here]<cost) continue;
    for(auto &p : adj[here]){
      int there = p.first;
      long long nextDist = cost + p.second;
      if(a[there] && there!=n-1) continue;
      if(dist[there]>nextDist){
        dist[there]=nextDist;
        pq.push({-nextDist,there});
      }
    }
  }
  if(dist[n-1]!=INF) cout << dist[n-1] << '\n';
  else cout << -1 << '\n';
}

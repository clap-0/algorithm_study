#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<pair<int,int> > adj[1001];
int dist[1001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, M;
  cin >> N >> M;
  for(int i=1; i<N; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    // 너비우선탐색 알고리즘을 통해 dist[i] = a에서 i까지 거리를 찾는다
    queue<int> Q;
    memset(dist, -1, sizeof(dist));
    Q.push(a);
    dist[a]=0;
    while(!Q.empty()&&dist[b]==-1){
      int curr=Q.front();
      Q.pop();
      for(auto& p : adj[curr]){
        int next=p.first, nextDist=p.second;
        if(dist[next]==-1){
          dist[next]=dist[curr]+nextDist;
          Q.push(next);
        }
      }
    }
    cout << dist[b] << '\n';
  }
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX=1001, INF=987654321;

vector<pair<int,int> > adj[MAX];
vector<int> dist(MAX,INF);

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }
  //다익스트라 알고리즘
  priority_queue<pair<int,int> > pq;
  int prev[MAX];
  pq.push({0,1});
  dist[1]=0;
  prev[1]=-1;
  while(!pq.empty()){
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();
    if(dist[here]<cost) continue;
    for(auto &p : adj[here]){
      int there = p.first, nextDist = dist[here]+p.second;
      if(dist[there]>nextDist){
        dist[there]=nextDist;
        pq.push({-nextDist, there});
        prev[there] = here;
      }
    }
  }
  //음수간선이 없으므로 n-1개의 1번 컴퓨터에서 각 컴퓨터로 가는 시간이
  //최소가 되는 회선만 복구하면 된다
  cout << n-1 << '\n';
  for(int i=2; i<=n; i++) cout << prev[i] << ' ' << i << '\n'; 
}

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX=10000, INF=987654321;

vector<pair<int,int> > adj[MAX];
vector<int> dist(MAX);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int tc;
  cin >> tc;
  while(tc--){
    int n, d, c;
    cin >> n >> d >> c; c--;
    //초기화
    for(int i=0; i<n; i++){
      adj[i].clear();
      dist[i]=INF;
    }
    for(int i=0; i<d; i++){
      int a, b, s;
      cin >> a >> b >> s; a--; b--;
      adj[b].push_back({a, s});
    }
    //다익스트라 알고리즘을 이용한 문제풀이
    int hackedComs=1, lastCom;
    priority_queue<pair<int,int> > pq;
    pq.push({0, c});
    dist[c]=0;
    while(!pq.empty()){
      int cost=-pq.top().first;
      int curr=pq.top().second;
      pq.pop();
      if(dist[curr]<cost) continue;
      hackedComs++; //처음 발견한 컴퓨터면 감염된 컴퓨터 수 최신화
      lastCom=curr; //마지막으로 방문한 컴퓨터 최신화
      for(auto &p : adj[curr]){
        int next = p.first, nextDist=cost+p.second;
        if(dist[next]>nextDist){
          dist[next]=nextDist;
          pq.push({-nextDist, next});
        }
      }
    }
    cout << hackedComs << ' ' << dist[lastCom] << '\n';
  }
}

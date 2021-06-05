#include <iostream>
#include <vector>
using namespace std;

const int MAX=500;
const long long INF=1e12;

vector<pair<int,int> > adj[MAX];
long long dist[MAX];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int tc;
  cin >> tc;
  while(tc--){
    int n, m, w;
    cin >> n >> m >> w;
    //초기화
    for(int i=0; i<n; i++){
      adj[i].clear();
      dist[i]=INF;
    }
    for(int i=0; i<m; i++){
      int s, e, t;
      cin >> s >> e >> t; s--; e--;
      adj[s].push_back({e,t});
      adj[e].push_back({s,t});
    }
    for(int i=0; i<w; i++){
      int s, e, t;
      cin >> s >> e >> t; s--; e--;
      adj[s].push_back({e,-t});
    }
    bool minusCycle=false; //음수사이클 존재여부
    bool visited[MAX]={false}; //각 정점의 방문여부
    //벨만포드 알고리즘
    for(int src=0; src<n; src++){
      if(visited[src]) continue;
      //한번도 방문한 적 없는 정점을 시작점으로 한다 
      dist[src]=0;
      visited[src]=true;
      for(int iter=0; iter<n; iter++)
        for(int here=0; here<n; here++){
          //다른 컴포넌트의 정점은 방문하지 않는다. 어차피 !visited[here]이면 dist[here]=INF.
          if(!visited[here]) continue;
          for(auto &p : adj[here]){
            int there = p.first, cost = p.second;
            visited[there]=true;
            if(dist[there]>dist[here]+cost){
              dist[there]=dist[here]+cost;
              if(iter==n-1) minusCycle=true; //음수사이클 확인
            }
          }
        }
      if(minusCycle) break; //음수사이클이 있는게 확인되면 다른 컴포넌트 탐색할 필요없이 종료
    }
    cout << (minusCycle ? "YES" : "NO") << '\n';
  }
}

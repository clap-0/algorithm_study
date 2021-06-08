#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX=100, INF=987654321;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  //인접리스트. (연결된 교차점, 갈취당하는 금품의 양) 저장. 금품의 양이 음수면 금품 획득 양
  vector<pair<int,int> > adj[MAX];
  //방향이 반대인 인접리스트
  vector<int> radj[MAX];
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u, v, w;
    cin >> u >> v >> w; u--; v--;
    adj[u].push_back({v,-w});
    radj[v].push_back(u);
  }
  //reachable[i] = i에서 목적지에 도달할 수 있는가
  bool reachable[MAX]={false};
  //너비우선탐색으로 목적지부터 역방향으로 탐색하여
  //목적지로 도달할 수 있는 교차점들 구함
  queue<int> q;
  q.push(n-1);
  reachable[n-1]=true;
  while(!q.empty()){
    int curr = q.front(); q.pop();
    for(int next : radj[curr])
      if(!reachable[next]){
        reachable[next]=true;
        q.push(next);
      }
  }
  //벨만-포드 알고리즘
  int lost[MAX], prev[MAX];
  bool minusCycle=false;
  fill(lost, lost+n, INF);
  lost[0]=0, prev[0]=-1;
  for(int iter=0; iter<n; iter++)
    for(int here=0; here<n; here++){
      if(lost[here]==INF) continue;
      for(auto &p : adj[here]){
        int there=p.first, cost=p.second;
        if(lost[there]>lost[here]+cost){
          lost[there]=lost[here]+cost;
          prev[there]=here;
          //출발점에서 목적지로 가는 최단경로에 음수사이클이 포함되어있는경우
          if(iter==n-1 && reachable[there]) minusCycle=true;
        }
      }
    }
  if(minusCycle || lost[n-1]==INF) cout << -1 << '\n';
  else{
    vector<int> path;
    for(int tmp=n-1; tmp!=-1; tmp=prev[tmp]) path.push_back(tmp+1);
    for(int i=path.size()-1; i>=0; i--) cout << path[i] << ' ';
  }
}

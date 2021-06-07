#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=100;
const long long INF=1e12;

int main()
{
  int n, s, e, m;
  vector<pair<int,int> > adj[MAX];
  //reachable[u][v] = u에서 v로 가는 경로의 존재여부
  bool reachable[MAX][MAX]={false};
  int earnings[MAX];
  cin >> n >> s >> e >> m;
  for(int i=0; i<m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
    reachable[u][v]=true;
  }
  for(int i=0; i<n; i++) cin >> earnings[i];
  //플로이드-와샬 알고리즘을 이용해 모든 정점쌍간의 도달가능성 구하기
  for(int i=0; i<n; i++) reachable[i][i]=true;
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++){
      if(!reachable[i][k]) continue;
      for(int j=0; j<n; j++)
        reachable[i][j]=reachable[i][j]||(reachable[i][k]&&reachable[k][j]);
    }
  //도착 도시에 도착하는게 불가능한 경우
  if(!reachable[s][e]){
    puts("gg");
    return 0;
  }
  //벨만-포드 알고리즘을 이용하여 시작도시에서
  //각 도시에 도착했을 때 가지고 있는 돈의 액수 최댓값 구하기
  long long lost[MAX]; //lost[i] = i에서 갖고 있는 돈을 음수로 저장. 양수면 적자
  bool minusCycle = false;
  fill(lost, lost+n, INF);
  lost[s]=-earnings[s];
  for(int iter=0; iter<n; iter++)
    for(int here=0; here<n; here++){
      if(lost[here]==INF) continue;
      for(auto &p : adj[here]){
        int there=p.first, cost=p.second;
        if(lost[there]>lost[here]+cost-earnings[there]){
          lost[there]=lost[here]+cost-earnings[there];
          //시작도시에서 도착도시로 가는 경로상에 음수사이클이 있는 경우
          if(iter==n-1 && (reachable[s][there]&&reachable[there][e])) minusCycle=true;
        }
      }
    }
  if(minusCycle) puts("Gee");
  else cout << -lost[e] << '\n';
}

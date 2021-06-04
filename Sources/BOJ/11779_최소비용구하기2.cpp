#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int MAX=1001, INF=987654321;

vector<pair<int,int> > adj[MAX];
vector<int> fare(MAX,INF); //fare[i] = 출발점에서 i까지 가는데 필요한 버스요금
int pre[MAX]; //출발점을 루트로 하는 스패닝트리상에서 부모노드

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m, start, end;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  cin >> start >> end;
  //다익스트라 알고리즘
  priority_queue<pair<int,int> > pq;
  pq.push({0,start});
  fare[start]=0;
  pre[start]=-1;
  while(!pq.empty()){
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();
    if(fare[here]<cost) continue;
    //도착점에 도달하면 탐색종료
    if(here==end) break;
    for(auto &p : adj[here]){
      int there = p.first, nextFare = p.second + fare[here];
      if(fare[there]>nextFare){
        fare[there]=nextFare;
        pq.push({-nextFare, there});
        pre[there]=here;
      }
    }
  }
  cout << fare[end] << '\n';
  stack<int> path;
  int tmp = end;
  while(tmp!=-1){
    path.push(tmp);
    tmp=pre[tmp];
  }
  cout << path.size() << '\n';
  while(!path.empty()){
    cout << path.top() << ' ';
    path.pop();
  }
}

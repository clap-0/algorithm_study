#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

const int MAX_N=300001, INF=987654321;

vector<int> adj[MAX_N];
vector<int> dist(MAX_N, INF);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m, k, x;
  cin >> n >> m >> k >> x;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  //다익스트라 알고리즘을 이용한 문제 풀이
  set<int> ans;
  priority_queue<pair<int,int> > pq;
  pq.push({0, x});
  dist[x]=0;
  while(!pq.empty()){
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();
    if(dist[here]<cost) continue;
    //최단거리가 k인 경우 답 목록에 추가
    if(cost==k) ans.insert(here);
    //최단거리가 k초과인 경우 더 이상 답을 찾을 수 없으므로 종료
    else if(cost>k) break;
    for(int there : adj[here]){
      int nextDist = cost+1;
      if(dist[there]>nextDist){
        dist[there]=nextDist;
        pq.push({-nextDist, there});
      }
    }
  }
  if(ans.empty()) cout << -1 << '\n';
  else for(int a : ans) cout << a << '\n';
}

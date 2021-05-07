#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX=501;
vector<int> adj[MAX]; //인접리스트
vector<int> indegrees(MAX); //indegrees[i] = i로 들어오는 간선의 수
vector<int> cost(MAX); //cost[i] = i를 짓는데 걸리는 시간
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> cost[i];
    int prev;
    while(1){
      cin >> prev;
      if(prev==-1) break;
      adj[prev].push_back(i);
      indegrees[i]++;
    }
  }
  //위상정렬
  vector<int> res(n+1, 0);
  queue<int> Q;
  
  //들어오는 간선이 하나도 없는 정점부터 시작
  for(int i=1; i<=n; i++)
    if(indegrees[i]==0){
      Q.push(i);
      res[i] = cost[i]; //이전에 지어야하는 건물이 없다는 뜻이므로 cost[i]와 같음
    }
  
  //들어오는 간선이 하나도 없는 정점을 방문하고 지우기를 반복하기
  for(int i=1; i<=n; i++){
    int curr = Q.front();
    Q.pop();
    for(int next : adj[curr]){
      if(--indegrees[next]==0) Q.push(next); //curr정점을 지웠을 때 들어오는 간선이 하나도 없으면 방문할 목록에 추가
      res[next] = max(res[next], res[curr]+cost[next]); //최소건설시간 갱신
    }
  }
  for(int i=1; i<=n; i++) cout << res[i] << '\n';
}

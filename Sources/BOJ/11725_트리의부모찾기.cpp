#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[100001]; //인접리스트
bool discovered[100001]; //이전에 해당 노드를 발견했는지 저장
int parent[100001]; //1번노드를 제외한 노드의 부모노드번호 저장
void bfs(int root)
{
  discovered[root] = true;
  queue<int> Q;
  Q.push(root);
  while(!Q.empty()){
    int curr = Q.front();
    Q.pop();
    for(auto next : adj[curr]){ //모든 인접노드 검사
      if(discovered[next]) continue; //이미 발견했던 노드면 패스
      Q.push(next);
      discovered[next] = true;
      parent[next] = curr; //해당노드의 부모노드 저장
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, u, v;
  cin >> n;
  for(int i=0; i<n-1; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bfs(1); //루트는 무조건 1
  for(int i=2; i<=n; i++) cout << parent[i] << '\n';
  return 0;
}

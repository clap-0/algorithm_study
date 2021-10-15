#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> adj[1001]; //인접리스트
vector<int> visited; //dfs에서 방문한 정점 저장
vector<int> discovered; //bfs에서 방문할 정점 저장
void dfs(int here)
{
  visited[here] = true;
  cout << here << ' '; //정점 here 방문하기
  for(auto there : adj[here]){
    if(!visited[there]) dfs(there);
  }
}
void bfs(int v)
{
  discovered[v] = true;
  queue<int> q;
  q.push(v);
  while(!q.empty()){
    int here = q.front();
    q.pop();
    cout << here << ' '; //정점 here방문하기
    for(auto there : adj[here])
      if(!discovered[there]){
        discovered[there] = true;
        q.push(there);
      }
  }
}
int main()
{
  int n, m, v;
  cin >> n >> m >> v;
  for(int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1; i<=n; i++)
    sort(adj[i].begin(), adj[i].end());
  visited.resize(n+1, 0);
  dfs(v); cout << '\n';
  discovered.resize(n+1, 0);
  bfs(v); cout << '\n';
  return 0;
}

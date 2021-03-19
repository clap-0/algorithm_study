#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > adj; //인접리스트
vector<bool> visited; //각 정점 방문여부
void dfs(int here)
{
  visited[here] = true;
  for(int i=0; i<adj[here].size(); i++){
    int there = adj[here][i];
    if(!(visited[there])) dfs(there);
  }
}
int main()
{
  int n, m, u, v, cnt=0;
  cin >> n >> m;
  adj.resize(n), visited.resize(n, false);
  for(int i=0; i<m; i++){
    cin >> u >> v;
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
  }
  for(int i=0; i<n; i++)
    if(!(visited[i])){
      dfs(i);
      cnt++;
    }
  cout << cnt << endl;
  return 0;
}

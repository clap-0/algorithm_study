#include <iostream>
#include <vector>
using namespace std;
const int MAX_N=100;
vector<vector<int> > adj(MAX_N+1);
bool visited[MAX_N+1];
int dfs(int here){
  int ret=1;
  visited[here] = true;
  for(auto& there : adj[here]){
    if(!visited[there]){
      ret += dfs(there);
    }
  }
  return ret;
}
int main()
{
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cout << dfs(1)-1 << endl;
  return 0;
}

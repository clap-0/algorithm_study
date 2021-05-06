#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> adj[32001];
vector<int> visited, row;
//깊이우선탐색을 통해 위상정렬하기
void dfs(int here){
  visited[here] = 1;
  for(int there : adj[here])
    if(!visited[there]) dfs(there);
  row.push_back(here);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  // dfs()가 종료될 때마다 정점번호 기록하고
  // 모든 정점 방문한 후에 기록된 순서 뒤집으면 위상정렬
  visited = vector<int>(n+1, 0);
  for(int i=1; i<=n; i++)
    if(!visited[i]) dfs(i);
  reverse(row.begin(), row.end());
  for(int order : row) cout << order << ' ';
}

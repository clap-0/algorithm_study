#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[100001];  // 그래프의 인접리스트 표현
int visited[100001];  // 각 노드의 방문 순서. 방문하지 않은 경우 0
int cnt;  // 노드 방문 순서 count

// 깊이우선탐색
void dfs(int here) {
  visited[here] = ++cnt;
  for(int there : adj[here])
    if(!visited[there]) dfs(there);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M, R;
  cin >> N >> M >> R;
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // 인접정점은 오름차순으로 방문하도록 각 노드의 인접 노드들을 오름차순으로 정렬한다
  for(int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());

  dfs(R);
  for(int i = 1; i <= N; i++) cout << visited[i] << '\n';
}

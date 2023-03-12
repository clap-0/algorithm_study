#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[500001];
bool visited[500001];

// DFS를 사용해서 루트에서 모든 리프 노드까지의 거리의 합을 구한다.
int dfs(int here, int depth)
{
  visited[here] = true;
  int ret = 0;
  
  for (int there : adj[here]) {
    if (!visited[there]) {
      ret += dfs(there, depth + 1);
    }
  }

  if (ret == 0) { // here번 노드가 리프노드인 경우
    ret = depth;
  }
  return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int totalDepth = dfs(1, 0);
  // 루트에서 모든 리프노드까지의 거리의 합이 홀수이면 게임을 이길 수 있다.
  cout << (totalDepth % 2 ? "Yes" : "No") << '\n';
}

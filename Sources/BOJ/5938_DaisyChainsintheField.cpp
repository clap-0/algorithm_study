#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[251];
bool visited[251];

void dfs(int here)
{
  visited[here] = true;
  for (int there : adj[here])
    if (!visited[there]) {
      dfs(there);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);
  // 1번 소와 연결되지 않은 소들을 찾는다.
  vector<int> misbehavers;
  for (int i = 2; i <= N; i++) {
    if (!visited[i]) {
      misbehavers.push_back(i);
    }
  }

  if (misbehavers.empty()) {  // 모든 소들이 1번 소와 연결된 경우
    cout << 0 << '\n';
  }
  else {
    for (int misbehaver : misbehavers) {
      cout << misbehaver << '\n';
    }
  }
}

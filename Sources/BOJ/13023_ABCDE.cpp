#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[2001];
bool visited[2001];

// DFS를 사용하여 깊이가 5이상이면 true를 아니면 false를 반환하는 함수
bool dfs(int here, int cnt = 1) {
  visited[here] = true;
  if(cnt == 5) return true;
  for(int there : adj[here])
    if(!visited[there] && dfs(there, cnt + 1)) return true;
  visited[here] = false;
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 0; i < N; i++)
    if(dfs(i)) {
      cout << 1 << '\n';
      return 0;
    }
  cout << 0 << '\n';
}

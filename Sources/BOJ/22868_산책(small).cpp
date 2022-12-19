#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[10001];
int visited[10001];

// S에서 E로 가는 최단경로의 길이를 구한다.
int getStrollDist(int S, int E)
{
  queue<int> Q;
  Q.push(S);
  visited[S] = S;
  int ret = 0, cnt = 0;
  while (!Q.empty()) {
    int qsize = Q.size();
    for (int i = 0; i < qsize; i++) {
      int curr = Q.front();
      Q.pop();
      for (int next : adj[curr])
        if (!visited[next]) {
          visited[next] = curr;
          if (next == E)
            return cnt + 1;
          Q.push(next);
        }
    }
    ++cnt;
  }
  return -1;
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

  // 각 인접리스트를 오름차순으로 정렬하여
  // getStrollDist 함수 실행시 사전순으로 가장 앞서는 최단경로의 길이를 반환하도록 한다.
  for (int i = 1; i <= N; i++)
    sort(adj[i].begin(), adj[i].end());

  int S, E;
  cin >> S >> E;
  int ans = getStrollDist(S, E);
  // S에서 E로 가는 사전순으로 가장 앞선 최단경로에 포함된 정점들을
  // 돌아가는 길에 경유하지 못하도록 한다.
  vector<int> path;
  for (int p = visited[E]; p != S; p = visited[p])
    path.push_back(p);
  memset(visited, 0, sizeof(visited));
  for (int p : path)
    visited[p] = true;
  // E에서 S로 돌아가는 최단경로의 길이
  ans += getStrollDist(S, E);
  cout << ans << '\n';
}

#include <iostream>
#include <vector>
using namespace std;

int N, S, D;
vector<int> adj[100001];  // 인접리스트
int dist[100001]; // 각 노드의 높이
bool visited[100001]; // 각 노드의 방문여부

// 깊이우선탐색을 이용하여 힘이 D일 때 이동해야 하는 총 거리 / 2 를 구한다
int dfs(int curr)
{
  visited[curr] = true;
  int ret = 0;
  for(int next : adj[curr])
    if(!visited[next])
    {
      int totalDist = dfs(next);
      // 리프 노드까지 힘 D로 전단지를 못 보내는 경우
      if(1 + dist[next] > D)
        ret += 1 + totalDist;
      dist[curr] = max(dist[curr], 1 + dist[next]);
    }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> S >> D;
  for(int i = 0; i < N - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  cout << 2 * dfs(S) << '\n';
}

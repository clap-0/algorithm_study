#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 40000;
const int LOG_N = 16; // log(2, MAX_N)의 올림

vector<pair<int,int> > adj[MAX_N];  // 가중그래프의 인접리스트
int parent[MAX_N][LOG_N + 1]; // parent[i][k] : 정점 i의 2^k번째 부모
int depth[MAX_N]; // 정점의 깊이 (루트의 깊이 : 0)
int dist[MAX_N];  // 루트에서 정점까지의 거리

// DFS로 인접리스트를 이용하여 0을 루트로 하는 트리를 만들고
// 배열 depth[]와 parent[][0], dist[]를 채운다
void makeTree(int node) {
  for(auto& p : adj[node]) {
    int child = p.first;
    if(depth[child] == -1) {
      depth[child] = depth[node] + 1;
      parent[child][0] = node;
      dist[child] = dist[node] + p.second;
      makeTree(child);
    }
  }
}

// 정점의 개수 N을 매개변수로 받아
// 트리를 만들고, parent 배열을 채운다
void init(int N) {
  memset(parent, -1, sizeof(parent));
  memset(depth, -1, sizeof(depth));
  depth[0] = 0;
  makeTree(0);  // 트리 만들기

  // (정점 i의 2ᶨ⁺¹ 번째 부모)는 (정점 i의 2ᶨ 번째 부모의 2ᶨ 번째 부모)와 같다
  for(int j = 0; j < LOG_N; j++)
    for(int i = 1; i < N; i++)
      if(parent[i][j] != -1) 
        parent[i][j + 1] = parent[parent[i][j]][j];
}

// 정점 u와 v의 최소 공통 조상을 찾아 반환한다
int getLCA(int u, int v) {
  // depth[u] >= depth[v]가 되도록 한다
  if(depth[u] < depth[v]) swap(u, v);

  // 깊이차 diff의 이진수 표현에서 켜져있는 비트만큼만 이동하면 depth[u] == depth[v]가 된다
  int diff = depth[u] - depth[v];
  while(diff) {
    int jump = __builtin_ctz(diff); // diff의 이진수표현에서 가장 오른쪽의 켜져있는 비트의 위치
    u = parent[u][jump];
    diff &= (diff - 1); // diff의 이진수표현에서 가장 오른쪽의 켜져있는 비트를 끈다
  }

  // u와 v가 다른 경우, 동시에 일정 높이만큼 위로 움직인다
  if(u != v) {
    for(int j = LOG_N; j >= 0; j--)
      if(parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
        u = parent[u][j];
        v = parent[v][j];
      }
    // 마지막에는 두 정점 u, v의 부모가 같으므로 한 번 더 올린다
    u = parent[u][0];
  }

  return u;
}

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w; u--; v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  init(N);

  cin >> M;
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v; u--; v--;
    // u와 v 사이의 거리는 루트에서 u까지의 거리와 루트에서 v까지의 거리의 합에서
    // 루트에서 두 정점의 최소공통조상까지의 거리를 두 번 뺀 것과 같다
    cout << dist[u] + dist[v] - 2 * dist[getLCA(u, v)] << '\n';
  }
}

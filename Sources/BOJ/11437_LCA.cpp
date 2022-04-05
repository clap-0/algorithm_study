#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 16; // log(2, 50000)의 올림

vector<int> adj[50000]; // 인접리스트
int parent[50000][MAX + 1]; // parent[i][k] : 정점 i의 2^k번째 부모
int depth[50000]; // 정점의 깊이 (루트의 깊이 : 0)

// DFS로 인접리스트를 이용하여 0을 루트로 하는 트리를 만들고
// 배열 depth[]와 parent[][0]을 채운다
void makeTree(int node) {
  for(int child : adj[node]) 
    if(depth[child] == -1) {
      depth[child] = depth[node] + 1;
      parent[child][0] = node;
      makeTree(child);
    }
}

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v; u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // 트리 만들기
  memset(parent, -1, sizeof(parent));
  memset(depth, -1, sizeof(depth));
  depth[0] = 0;
  makeTree(0);

  // parent 배열의 나머지 부분을 채운다
  for(int j = 0; j < MAX; j++)
    for(int i = 1; i < N; i++)
      // (정점 i의 2ᶨ⁺¹ 번째 부모)는 (정점 i의 2ᶨ 번째 부모의 2ᶨ 번째 부모)와 같다. (2ⁿ⁺¹ == 2ⁿ * 2ⁿ)
      if(parent[i][j] != -1)
        parent[i][j + 1] = parent[parent[i][j]][j];

  cin >> M;
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v; u--; v--;

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
      for(int j = MAX; j >= 0; j--)
        if(parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
          u = parent[u][j];
          v = parent[v][j];
        }
      
      // 마지막에는 두 정점 u, v의 부모가 같으므로 한 번 더 올린다
      u = parent[u][0];
    }

    cout << u + 1 << '\n';
  }
}

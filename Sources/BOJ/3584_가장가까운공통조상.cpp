#include <iostream>
#include <cstring>
using namespace std;

const int LOGN = 14;  // log(2, 10000)의 올림

int parent[10001][LOGN];  // parent[i][k] : 정점 i의 2^k번째 부모
int depth[10001]; // 정점의 깊이 (루트의 깊이 : 1)

// node노드의 깊이를 반환하는 함수
int computeDepth(int node) {
  if(depth[node]) return depth[node];
  return depth[node] = 1 + computeDepth(parent[node][0]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    memset(parent, 0, sizeof(parent));
    memset(depth, 0, sizeof(depth));
    for(int i = 0; i < N - 1; i++) {
      int A, B;
      cin >> A >> B;
      parent[B][0] = A;
    }

    // 루트 번호를 구함
    int root = 1;
    while(parent[root][0]) root = parent[root][0];

    // parent 배열의 나머지 부분을 채운다
    // (정점 i의 2ᶨ⁺¹ 번째 부모)는 (정점 i의 2ᶨ 번째 부모의 2ᶨ 번째 부모)와 같다. (2ⁿ⁺¹ == 2ⁿ * 2ⁿ)
    for(int j = 0; j < LOGN - 1; j++)
      for(int i = 1; i <= N; i++)
        if(parent[i][j])
          parent[i][j + 1] = parent[parent[i][j]][j];
    
    depth[root] = 1;
    for(int i = 1; i <= N; i++) computeDepth(i);

    int u, v;
    cin >> u >> v;
    
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
      for(int j = LOGN - 1; j >= 0; j--)
        if(parent[u][j] && parent[u][j] != parent[v][j]) {
          u = parent[u][j];
          v = parent[v][j];
        }
      // 마지막에는 두 정점 u, v의 부모가 같으므로 한 번 더 올린다
      u = parent[u][0];
    }

    cout << u << '\n';
  }
}

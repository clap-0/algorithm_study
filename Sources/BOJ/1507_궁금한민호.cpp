#include <iostream>
#include <cstring>
using namespace std;

int adj[20][20];
bool path[20][20];  // 도로의 개수를 최소로 만들었을 때 두 도시 사이의 직접적인 경로의 존재여부

// 플로이드-와샬 알고리즘을 이용하여 도로의 개수를 최소로 만든다
// 두 도시 사이를 간접적으로 이동했을 때 직접적으로 이동 시 걸리는 시간보다 짧은 경우
// adj[][]가 모든 쌍의 도시 사이의 최소이동시간이라는 조건에 어긋나므로 false를 반환한다
bool floyd(int N) {
  for(int k = 0; k < N; k++)
    for(int i = 0; i < N; i++) {
      if(i == k) continue;
      for(int j = 0; j < N; j++) {
        if(j == k) continue;
        // i -> k -> j와 i -> j가 걸리는 시간이 같으므로 i -> j 경로는 필요없다
        if(adj[i][k] + adj[k][j] == adj[i][j]) path[i][j] = false;
        // i -> k -> j가 i -> j보다 걸리는 시간이 짧으므로 주어진 조건에 어긋난다
        else if(adj[i][k] + adj[k][j] < adj[i][j]) return false;
      }
    }
  return true;
}

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++) cin >> adj[i][j];
    
  memset(path, true, sizeof(path));
  if(floyd(N)) {
    int ans = 0;
    // adj[i][j] == adj[j][i]이므로 둘 중 하나만 더한다
    for(int i = 0; i < N; i++)
      for(int j = i + 1; j < N; j++)
        if(path[i][j]) ans += adj[i][j];
    cout << ans << '\n';
  }
  else cout << -1 << '\n';
}

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 501;

int adj[MAX_N][MAX_N];  // 인접 행렬
int indegrees[MAX_N];   // 진입 차수

// 위상 정렬 알고리즘을 이용하여 올해 최종 순위를 출력한다.
void topologicalSort(int N) {
  int result[MAX_N];
  
  // 큐에 진입차수가 0인 정점들을 담는다.
  queue<int> Q;
  for(int i = 1; i <= N; i++)
    if(indegrees[i] == 0) Q.push(i);
  
  for(int n = 0; n < N; n++) {
    if(Q.empty()) { // 큐가 비어있는 경우, 데이터에 일관성이 없다(사이클 발생)
      cout << "IMPOSSIBLE\n"; return;
    }
    else if(Q.size() > 1) { // 큐의 크기가 2이상인 경우, 확실한 순위를 찾을 수 없다(여러 개의 위상 정렬 결과 존재)
      cout << "?\n"; return;
    }

    // curr 정점과 curr에서 나가는 간선들을 지운다.
    int curr = Q.front(); Q.pop();
    for(int i = 1; i <= N; i++)
      if(adj[curr][i]) {
        adj[curr][i] = false;
        // 진입차수가 0인 정점이 생기면 큐에 담는다.
        if(--indegrees[i] == 0) Q.push(i);
      }
    // 지운 정점을 순서가 위상 정렬 결과이다.
    result[n] = curr;
  }

  for(int i = 0; i < N; i++) cout << result[i] << ' ';
  cout << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T, n, m;
  int rank[MAX_N];
  cin >> T;
  while(T--) {
    memset(indegrees, 0, sizeof(indegrees));
    memset(adj, 0, sizeof(adj));

    cin >> n;
    for(int i = 0; i < n; i++) {
      int team;
      cin >> team;
      rank[i] = team;
      indegrees[team] = i;
    }
    // 순위가 높은 팀이 낮은 팀을 가리키는 방향 그래프를 만든다.
    for(int i = 0; i < n - 1; i++) 
      for(int j = i + 1; j < n; j++)
        adj[rank[i]][rank[j]] = true;

    // 주어진 두 팀을 잇는 간선의 방향을 바꾼다
    cin >> m;
    for(int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      if(adj[b][a]) swap(a, b);
      adj[a][b] = false; --indegrees[b];
      adj[b][a] = true; ++indegrees[a];
    }

    topologicalSort(n);
  }
}

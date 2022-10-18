#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, p, q;
    cin >> n >> p >> q;
    
    vector<int> pos(n); // n명의 사람들의 위치
    vector<vector<int> > adj(p + 1, vector<int>(p + 1, INF)); // 인접행렬
    
    for (int i = 0; i < n; i++)
      cin >> pos[i];
    for (int i = 0; i < q; i++)
    {
      int u, v, d;
      cin >> u >> v >> d;
      // 양방향 그래프이고, 인접행렬에는 가장 가중치가 작은 간선만을 저장한다.
      adj[u][v] = adj[v][u] = min(d, adj[u][v]);
    }
    // 같은 정점 사이의 거리 = 0
    for (int i = 1; i <= p; i++)
      adj[i][i] = 0;

    // Floyd-Warshall
    for (int k = 1; k <= p; k++)
      for (int i = 1; i <= p; i++)
        if (adj[i][k] != INF)
          for (int j = 1; j <= p; j++)
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    int closestPos;
    long long cost = 10LL * INF;
    for (int i = 1; i <= p; i++)
    {
      long long sum = 0LL;
      for (int j = 0; j < n; j++)
      {
        // 특정 사람이 i번 은하로 가는 경로가 없는 경우
        // i번 은하는 모임장소가 될 수 없다.
        if (adj[i][pos[j]] == INF)
        {
          sum = 10LL * INF;
          break;
        }
        // i번 은하가 모임장소일 때 최소 지출액
        sum += adj[i][pos[j]] * adj[i][pos[j]];
      }
      if (cost > sum)
      {
        cost = sum;
        closestPos = i;
      }
    }
    cout << closestPos << ' ' << cost << '\n';
  }
}

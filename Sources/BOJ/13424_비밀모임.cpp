#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while (T--)
  {
    int N, M, K;
    cin >> N >> M;
    
    vector<vector<int> > adj(N, vector<int>(N, INF)); // 인접행렬
    for (int i = 0; i < N; i++)
      adj[i][i] = 0;
    
    for (int i = 0; i < M; i++)
    {
      int a, b, c;
      cin >> a >> b >> c; a--; b--;
      adj[a][b] = adj[b][a] = c;
    }
    cin >> K;
    vector<int> friends(K);
    for (int i = 0; i < K; i++)
      cin >> friends[i];

    // 플로이드 알고리즘
    for (int k = 0; k < N; k++)
      for (int i = 0; i < N; i++)
        if (adj[i][k] != INF)
          for (int j = 0; j < N; j++)
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    int ans = -1, minDist = INF;
    for (int i = 0; i < N; i++)
    {
      int sum = 0;
      for (int pos : friends)
        sum += adj[pos - 1][i];
      if (sum < minDist)
      {
        minDist = sum;
        ans = i;
      }
    }

    cout << ans + 1 << '\n'; 
  }
}

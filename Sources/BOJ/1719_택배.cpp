#include <iostream>
using namespace std;

int adj[201][201];
int path[201][201];

int main()
{
  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      adj[i][j] = (i != j ? 987654321 : 0);

  for(int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u][v] = adj[v][u] = w;
    path[u][v] = v;
    path[v][u] = u;
  }

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      if(path[i][k])
        for(int j = 1; j <= n; j++)
          if(adj[i][j] > adj[i][k] + adj[k][j])
          {
            adj[i][j] = adj[i][k] + adj[k][j];
            path[i][j] = path[i][k];
          }
  
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
      if(i != j)
        cout << path[i][j] << ' ';
      else
        cout << "- ";
    cout << '\n';
  }
}

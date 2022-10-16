#include <iostream>
using namespace std;

int adj[500][500];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> adj[i][j];
  
  // floyd's algorithm
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++) {
      if (i == k) continue;
      for (int j = 0; j < N; j++)
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    }

  while (M--)
  {
    int A, B, C;
    cin >> A >> B >> C;
    cout << (adj[A - 1][B - 1] <= C ? "Enjoy other party\n" : "Stay here\n");
  }
}

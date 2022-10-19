#include <iostream>
using namespace std;

const int INF = 987654321;

int adj[200][200];

int main()
{
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      adj[i][j] = INF;
    adj[i][i] = 0;
  }

  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C; --A; --B;
    adj[A][B] = adj[B][A] = min(C, adj[A][B]);
  }

  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      if (adj[i][k] != INF)
        for (int j = 0; j < N; j++)
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

  int minSum = INF, ans = -1;
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) 
      sum += adj[i][j];
    if (minSum > sum) {
      minSum = sum;
      ans = i;
    }
  }

  cout << ans + 1 << '\n';
}

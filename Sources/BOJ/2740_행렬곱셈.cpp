#include <iostream>
using namespace std;

int A[100][100], B[100][100], C[100][100];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M, K;
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> A[i][j];
  cin >> M >> K;
  for (int i = 0; i < M; i++)
    for(int j = 0; j < K; j++)
      cin >> B[i][j];

  for (int r = 0; r < N; r++)
    for (int c = 0; c < K; c++)
      for (int i = 0; i < M; i++)
        C[r][c] += A[r][i] * B[i][c];
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++)
      cout << C[i][j] << ' ';
    cout << '\n';
  }
}

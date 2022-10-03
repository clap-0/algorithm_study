#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int> > Matrix;

int N, M, P;
Matrix matrix;

// 행렬 A와 행렬 B를 곱한 결과를 반환한다
Matrix multiply(const Matrix& A, const Matrix& B)
{
  Matrix ret = Matrix(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++) {
        ret[i][j] += A[i][k] * B[k][j];
        ret[i][j] %= M;
      }
  return ret;
}

// matrix행렬을 k번 거듭제곱한 결과를 반환한다
Matrix pow(int k)
{
  if (k == 1)
    return matrix;
  if (k & 1)
    return multiply(matrix, pow(k - 1));
  Matrix half = pow(k / 2);
  return multiply(half, half);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  while (true)
  {
    cin >> N >> M >> P;
    if (N == 0)
      break;

    matrix = Matrix(N, vector<int>(N));
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        cin >> matrix[i][j];

    Matrix ans = pow(P);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
        cout << ans[i][j] << ' ';
      cout << '\n';
    }
    cout << '\n';
  }
}

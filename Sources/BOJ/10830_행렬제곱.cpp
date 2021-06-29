#include <cstdio>
#include <vector>
using namespace std;
int N;
typedef vector<vector<int> > matrix;
//연산자 오버로딩을 통해 정방행렬곱셈 계산
matrix operator*(matrix &a, matrix &b){
  matrix temp(N, vector<int>(N,0));
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
      for(int k=0; k<N; k++) temp[i][j] += a[i][k] * b[k][j];
      temp[i][j] %= 1000;
    }
  return temp;
}
int main()
{
  matrix A, res;
  long long B;
  scanf("%d %lld", &N, &B);
  res = A = matrix(N, vector<int>(N,0));
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      scanf("%d", &A[i][j]);
  //행렬제곱 계산
  for(int i=0; i<N; i++) res[i][i] = 1;
  while(B>0){
    if(B%2) res = res * A;
    A = A*A;
    B/=2;
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++) printf("%d ", res[i][j]);
    puts("");
  }
}

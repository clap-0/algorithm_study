#include <cstdio>

int N, M;
int A[50][50], B[50][50];

int solve(){
  int ret=0;
  // A의 왼쪽 위부터 오른쪽 아래로 가며,
  // B와 다른 곳이 있다면 해당 칸을 왼쪽 위 칸으로 하는 3*3칸을 뒤집는다.
  // 이때 뒤집는 칸이 범위를 벗어난다면 -1을 리턴한다
  for(int n=0; n<N; n++)
    for(int m=0; m<M; m++)
      if(A[n][m] != B[n][m]){
        ++ret;
        for(int i=0; i<3; i++)
          for(int j=0; j<3; j++){
            if(n+i>=N || m+j>=M) return -1;
            A[n+i][m+j] = 1-A[n+i][m+j];
          }
      }
  return ret;
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      scanf("%1d", &A[i][j]);
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      scanf("%1d", &B[i][j]);

  printf("%d\n", solve());
}

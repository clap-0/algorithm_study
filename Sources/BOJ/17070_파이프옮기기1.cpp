#include <cstdio>
#include <cstring>
using namespace std;
const int MAX=16, VERT=0, HORIZ=1, DIAG=2;
int N;
int house[MAX][MAX], cache[MAX][MAX][3];
//파이프의 우측 끝의 위치(r,c)와 파이프가 놓인 방향이 주어졌을 때
//DP를 이용하여 파이프를 이동시키는 방법의 수를 구한다
//dir이 0이면 가로, 1이면 세로, 2이면 대각선이다
int movePipe(int r, int c, int dir){
  //메모이제이션
  int& ret = cache[r][c][dir];
  if(ret!=-1) return ret;
  //기저사례 : 목표지점에 도달한 경우 1 반환
  if(r==N-1 && c==N-1) return 1;
  ret=0;
  //현재 세로방향이 아니고 중간에 장애물이 없는 경우 가로로 민다
  if(dir!=HORIZ && c+1<N && house[r][c+1]==0) ret += movePipe(r, c+1, VERT);
  //현재 가로방향이 아니고 중간에 장애물이 없는 경우 세로로 민다
  if(dir!=VERT && r+1<N && house[r+1][c]==0) ret += movePipe(r+1, c, HORIZ);
  //중간에 장애물이 없는 경우 대각선으로 민다
  if(c+1<N && r+1<N && house[r][c+1]==0 && house[r+1][c]==0 && house[r+1][c+1]==0) ret += movePipe(r+1, c+1, DIAG);
  return ret;
}
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      scanf("%d", &house[i][j]);
  memset(cache, -1, sizeof(cache));
  printf("%d\n", movePipe(0, 1, 0));
}

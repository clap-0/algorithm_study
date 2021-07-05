#include <cstdio>
#include <cstring>
using namespace std;
const int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};
int M, N;
int height[500][500], cache[500][500];
//DP를 이용하여 {y,x}에서 {N-1,M-1}로 가는 경로의 수 구하기
int countPath(int y, int x){
  //기저사례 : 목적지에 도착 시 1 반환
  if(y==M-1 && x==N-1) return 1;
  //메모이제이션
  int& ret = cache[y][x];
  if(ret!=-1) return ret;
  ret=0;
  //상하좌우에서 높이가 더 낮은 지점으로만 
  for(int i=0; i<4; i++){
    int ny=y+dy[i], nx=x+dx[i];
    if(ny<0||nx<0||ny>=M||nx>=N) continue;
    if(height[y][x]>height[ny][nx]) ret+=countPath(ny, nx);
  }
  return ret;
}
int main()
{
  scanf("%d %d", &M, &N);
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++) scanf("%d", &height[i][j]);
  memset(cache, -1, sizeof(cache));
  printf("%d\n", countPath(0,0));
}

#include <iostream>
#include <cstring>
using namespace std;
const int HORIZ=0, VERT=1, DIAG=2;
int N;
bool map[32][32];
long long cache[32][32][3];
//DP를 이용하여 파이프 한쪽 끝의 위치와 놓인 방향이 주어질 때 
//한쪽 끝을 맨 오른쪽아래로 옮기는 방법의 수를 구한다
long long movingPipe(int r, int c, int dir){
  //기저사례 : 목표지점에 파이프 끝을 옮긴 경우
  if(r==N-1 && c==N-1) return 1;
  //메모이제이션
  long long& ret = cache[r][c][dir];
  if(ret!=-1) return ret;
  ret=0;
  //파이프가 가로로 놓이지 않았다면 세로로 민다
  if(dir!=HORIZ && r+1<N && !map[r+1][c]) ret += movingPipe(r+1, c, VERT);
  //파이프가 세로로 놓이지 않았다면 가로로 민다
  if(dir!=VERT && c+1<N && !map[r][c+1]) ret += movingPipe(r, c+1, HORIZ);
  //장애물이 없는 경우 대각선으로 민다
  if(r+1<N && c+1<N && !map[r+1][c] && !map[r][c+1] && !map[r+1][c+1]) ret += movingPipe(r+1, c+1, DIAG);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      cin >> map[i][j];
  memset(cache, -1, sizeof(cache));
  cout << movingPipe(0, 1, HORIZ) << '\n';
}

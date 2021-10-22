#include <cstdio>
const int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};
int N, M;
bool isWhite[500][500], visited[100][100];
// 깊이우선탐색 알고리즘
int dfs(int y, int x){
  visited[y][x]=true;
  int ret=0;
  // 인접한 같은 군의 병사수를 구한다
  for(int i=0; i<4; i++){
    int ny=y+dy[i], nx=x+dx[i];
    if(ny<0||nx<0||ny>=M||nx>=N) continue;
    if(visited[ny][nx]||isWhite[y][x]!=isWhite[ny][nx]) continue;
    ret+=dfs(ny, nx);
  }
  return ret+1;
}
int main()
{
  scanf("%d %d", &N, &M);
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++){
      char color;
      scanf(" %c", &color);
      isWhite[i][j]=color=='W';
    }
  int wForce=0, bForce=0;
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++)
      if(!visited[i][j]){
        int gathered=dfs(i, j);
        if(isWhite[i][j]) wForce+=gathered*gathered;
        else bForce+=gathered*gathered;
      }
  printf("%d %d\n", wForce, bForce);
}

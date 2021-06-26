#include <cstdio>
#include <cstring>
using namespace std;
const int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};
int N;
int height[100][100];
bool visited[100][100];
//DFS를 이용하여 {y,x}와 인접한 높이가 h이상인 지역들 탐색
void safetyZone(int y, int x, int h){
  visited[y][x]=true;
  for(int i=0; i<4; i++){
    int ny=y+dy[i], nx=x+dx[i];
    if(ny<0||nx<0||ny>=N||nx>=N) continue;
    if(height[ny][nx]>=h&&!visited[ny][nx]) safetyZone(ny,nx,h);
  }
}
int main()
{
  int ans=0, maxHeight=0;
  scanf("%d", &N);
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
      scanf("%d", &height[i][j]);
      if(maxHeight<height[i][j]) maxHeight=height[i][j];
    }
  for(int h=1; h<=maxHeight; h++){
    int cnt=0;
    for(int i=0; i<N; i++) memset(visited[i], 0, sizeof(visited[i]));
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
        if(height[i][j]>=h&&!visited[i][j]){
          safetyZone(i, j, h);
          cnt++;
        }
    if(ans<cnt) ans=cnt;
  }
  printf("%d\n", ans);
}

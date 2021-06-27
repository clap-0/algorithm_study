#include <cstdio>
using namespace std;
//dy[d] = d방향을 바라보고 있을 때 왼쪽 칸과의 y좌표 차이
//dx[d] = d방향을 바라보고 있을 때 왼쪽 칸과의 x좌표 차이
const int dy[4]={0,-1,0,1}, dx[4]={-1,0,1,0};
int N, M;
int room[50][50];
//해당 위치의 청소여부
bool cleaned[50][50];
int main()
{
  int r, c, d, ans=1;
  scanf("%d %d", &N, &M);
  scanf("%d %d %d", &r, &c, &d);
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      scanf("%d", &room[i][j]);
  
  cleaned[r][c]=true;
  while(1){
    //왼쪽방향에 아직 청소하지 않은 공간 존재 여부
    bool found=false;
    //왼쪽방향으로 돌아가며 청소할 공간이 있는지 찾는다
    for(int i=0; i<4; i++){
      int ny=r+dy[d], nx=c+dx[d];
      d = (d+3)%4;
      //왼쪽방향에 청소할 공간이 없는 경우
      if(ny<0||nx<0||ny>=N||nx>=M||cleaned[ny][nx]||room[ny][nx]) continue;
      //아직 청소하지 않은 공간이 있다면 그 칸으로 가서 청소한다
      r=ny, c=nx, found=true;
      cleaned[r][c]=true;
      ans++;
      break;
    }
    if(found) continue;
    //네방향 모두 청소할 공간이 없는 경우 뒤에 벽이 없으면 후진하고, 있으면 종료한다
    int backY=r+dy[(d+3)%4], backX=c+dx[(d+3)%4];
    if(!room[backY][backX]) r=backY, c=backX;
    else break;
  }
  printf("%d\n", ans);
}

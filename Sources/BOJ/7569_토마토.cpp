#include <iostream>
#include <queue>
using namespace std;
const int MAX=100; //m,n,h의 가능한 최댓값
int adj[MAX][MAX][MAX];
int timeTaken[MAX][MAX][MAX]; //각 칸이 익을 때까지 걸린 시간
int dz[6]={-1,0,0,0,0,1}, dy[6]={0,-1,0,0,1,0}, dx[6]={0,0,-1,1,0,0};
int main()
{
  int m, n, h;
  int ans=0, unripe=0;
  queue<int> q; //int대신 구조체나 pair<pair<int,int> >도 사용가능
  cin >> m >> n >> h;
  for(int i=0; i<h; i++)
    for(int j=0; j<n; j++)
      for(int k=0; k<m; k++){
        cin >> adj[i][j][k];
        if(adj[i][j][k]==0) unripe++; //설익은 토마토 개수 파악
        else if(adj[i][j][k]==1) q.push(i*MAX*MAX+j*MAX+k); //익은 토마토의 위치 저장
      }
  while(!q.empty()){
    int z=q.front()/(MAX*MAX), y=(q.front()/MAX)%MAX, x=q.front()%MAX;
    q.pop();
    ans=timeTaken[z][y][x];
    for(int i=0; i<6; i++){
      int nz=z+dz[i], ny=y+dy[i], nx=x+dx[i];
      if(nz<0||ny<0||nx<0||nz>=h||ny>=n||nx>=m) continue;
      if(adj[nz][ny][nx]==0){ //익은 토마토와 인접한 설익은 게 있는 경우
        adj[nz][ny][nx]=1;
        timeTaken[nz][ny][nx]=timeTaken[z][y][x]+1;
        unripe--;
        q.push(nz*MAX*MAX+ny*MAX+nx);
      }
    }
  }
  if(unripe==0) cout << ans << endl; //모든 토마토가 익은 경우
  else cout << -1 << endl; //설익은 토마토가 있는 경우
  return 0;
}

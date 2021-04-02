#include <iostream>
#include <queue>
using namespace std;
int m,n;
int adj[1000][1000];
int timeTaken[1000][1000]; //각 칸의 토마토가 익는데 걸리는 시간
int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};
int main()
{
  int ans=0, unripe=0;
  queue<pair<int,int> > q;
  cin >> m >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++){
      cin >> adj[i][j];
      if(adj[i][j]==0) unripe++; //설익은 토마토 개수 세기
      else if(adj[i][j]==1) q.push({i,j}); //큐에 익은 토마토 저장
    }
  //너비우선탐색
  while(!q.empty()){
    int y=q.front().first, x=q.front().second;
    q.pop();
    ans=timeTaken[y][x]; //마지막 토마토가 익는데 걸린 시간이 답
    for(int i=0; i<4; i++){
      int ny=y+dy[i], nx=x+dx[i];
      if(ny<0||nx<0||ny>=n||nx>=m) continue;
      if(adj[ny][nx]==0){
        adj[ny][nx]=1;
        timeTaken[ny][nx]=timeTaken[y][x]+1;
        unripe--;
        q.push({ny,nx});
      }
    }
  }
  if(unripe==0) cout << ans << endl; //모든 설익은 토마토가 익으면 답 출력
  else cout << -1 << endl; //토마토가 모두 익지 못하면 -1 출력
  return 0;
}

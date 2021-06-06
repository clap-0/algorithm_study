#include <iostream>
#include <queue>
using namespace std;
const int MAX=1001;
const int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};
char adj[MAX][MAX];
//discovered[i][j][k] = i행j열 칸을 발견했는지 여부. k=0이면 이 칸에 오기까지 벽을 안 부숨, 1이면 부숨
bool discovered[MAX][MAX][2];
int main()
{
  int n, m;
  queue<int> q;
  cin >> n >> m;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      cin >> adj[i][j];
  //1행 1열에서 시작
  q.push(1*MAX+1);
  discovered[1][1][0]=true;
  //너비우선탐색을 통해 n행m열까지의 최단경로길이를 구한다
  //어떤 칸을 방문하기까지 벽을 부순 적이 있으면 음수로, 없으면 양수로 큐에 좌표값을 넣는다
  int ans=1;
  while(!q.empty()){
    int qsize=q.size();
    for(int i=0; i<qsize; i++){
      int curr=q.front(); q.pop();
      //이 칸에 오기까지 벽을 부순적이 있는가
      bool smashed = curr<0;
      curr *= (smashed?-1:1);
      //n행m열에 도달한 경우 최단경로길이 출력
      if(curr/MAX==n && curr%MAX==m){
        cout << ans << '\n';
        return 0;
      }
      //상하좌우 이동
      for(int i=0; i<4; i++){
        int ny=curr/MAX+dy[i], nx=curr%MAX+dx[i];
        if(ny<=0||nx<=0||ny>n||nx>m) continue; //범위 밖인 경우 패스
        if(discovered[ny][nx][smashed]) continue; //이미 발견한 칸이면 패스
        if(adj[ny][nx]=='1'){ //가려는 칸이 벽인 경우
          if(smashed) continue; //이미 한번 벽을 부쉈으면 패스
          q.push(-(ny*MAX+nx));
          discovered[ny][nx][1]=true;
        }
        else{ //가려는 칸이 이동가능한 경우
          q.push((ny*MAX+nx)*(smashed?-1:1));
          discovered[ny][nx][smashed]=true;
        }
      }
    }
    ans++;
  }
  cout << -1 << '\n';
}

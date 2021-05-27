#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};

int n, m, ans;
int adj[8][8];
vector<pair<int,int> > virusPos; //초기 바이러스의 위치

//너비우선탐색을 통해 현재 상태에서 감염된 칸들을 구하고
//현재 상태에서 안전영역의 크기를 구한다.
int bfs(){
  bool infected[8][8]={0}; //이 칸에 바이러스가 퍼졌는가
  queue<pair<int,int> > q;
  for(auto pos : virusPos){
    q.push(pos);
    infected[pos.first][pos.second]=true;
  }
  while(!q.empty()){
    int y=q.front().first, x=q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      int ny=y+dy[i], nx=x+dx[i];
      if(ny<0||nx<0||ny>=n||nx>=m) continue; //연구소의 범위 밖이면 패스
      if(infected[ny][nx] || adj[ny][nx]!=0) continue; //이미 바이러스가 퍼진 칸이거나 빈 칸이 아니면 패스
      q.push({ny,nx});
      infected[ny][nx]=true;
    }
  }
  //안전영역의 크기 구하기
  int ret=0;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(infected[i][j]==0 && adj[i][j]==0) ret++;
  return ret;
}

//완전탐색을 통해 벽을 세울 곳을 구한다
void dfs(int y, int x, int cnt){
  adj[y][x]=1;
  if(cnt==2){
    ans = max(ans,bfs());
  }
  else{
    for(int i=y; i<n; i++)
      for(int j=0; j<m; j++)
        if(adj[i][j]==0) dfs(i, j, cnt+1);
  }
  adj[y][x]=0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++){
      cin >> adj[i][j];
      if(adj[i][j]==2) virusPos.push_back({i,j});
    }
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(adj[i][j]==0) dfs(i, j, 0);
  cout << ans << '\n';
}

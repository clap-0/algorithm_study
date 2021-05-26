#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};
int h, w;
vector<string> adj;
int discovered[50][50];

int bfs(int startY, int startX){
  memset(discovered, -1, sizeof(discovered));
  queue<pair<int,int> > q;
  int ret=0;
  q.push({startY,startX});
  discovered[startY][startX]=0;
  while(!q.empty()){
    int y=q.front().first, x=q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      int ny=y+dy[i], nx=x+dx[i];
      if(ny<0||nx<0||ny>=h||nx>=w) continue;
      if(adj[ny][nx]=='W' || discovered[ny][nx]!=-1) continue;
      q.push({ny,nx});
      discovered[ny][nx]=discovered[y][x]+1;
      ret=max(ret, discovered[ny][nx]);
    }
  }
  return ret;
}

int main()
{
  cin >> h >> w;
  for(int i=0; i<h; i++){
    string s;
    cin >> s;
    adj.push_back(s);
  }
  
  int ans=0;
  for(int i=0; i<h; i++)
    for(int j=0; j<w; j++)
      if(adj[i][j]=='L') ans=max(ans, bfs(i,j));
  cout << ans << '\n';
}

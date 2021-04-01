#include <iostream>
#include <queue>
using namespace std;
int w, h;
int dy[8]={-1,-1,-1,0,0,1,1,1}, dx[8]={-1,0,1,-1,1,-1,0,1};
bool adj[50][50];
bool discovered[50][50];
//너비우선탐색을 통해 가로,세로,대각선으로 연결된 사각형 찾기
void bfs(int y, int x){
  discovered[y][x]=true;
  queue<pair<int,int> > q;
  q.push({y,x});
  while(!q.empty()){
    int currY=q.front().first, currX=q.front().second;
    q.pop();
    for(int i=0; i<8; i++){
      int nextY=currY+dy[i], nextX=currX+dx[i];
      if(nextY<0||nextX<0||nextY>=h||nextX>=w) continue;
      if(adj[nextY][nextX]&&!discovered[nextY][nextX]){
        discovered[nextY][nextX]=true;
        q.push({nextY, nextX});
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  while(1){
    cin >> w >> h;
    if(w==0&&h==0) break;
    int cnt=0;
    for(int i=0; i<h; i++)
      for(int j=0; j<w; j++){
        cin >> adj[i][j];
        discovered[i][j]=false;
      }
    for(int i=0; i<h; i++)
      for(int j=0; j<w; j++)
        if(!discovered[i][j]&&adj[i][j]){
          cnt++;
          bfs(i, j);
        }
    cout << cnt << endl;
  }
}

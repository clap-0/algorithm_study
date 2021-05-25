#include <iostream>
#include <queue>
using namespace std;

struct monkey{
  int y, x, k, move;
  monkey(int _y, int _x, int _k, int _move) : y(_y), x(_x), k(_k), move(_move) {}
};

int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0}; //상하좌우 움직임
int hy[8]={-1,-2,-2,-1,1,2,2,1}, hx[8]={-2,-1,1,2,2,1,-1,-2}; //말의 움직임

int main()
{
  int k, w, h;
  int adj[200][200];
  bool discovered[200][200][31]={0};
  queue<monkey> q;
  
  cin >> k >> w >> h;
  for(int i=0; i<h; i++)
    for(int j=0; j<w; j++)
      cin >> adj[i][j];
  
  q.push(monkey(0,0,k,0));
  discovered[0][0][k]=true;
  while(!q.empty()){
    monkey curr = q.front(); q.pop();
    if(curr.y==h-1 && curr.x==w-1){ //목적지 도착한 경우
      cout << curr.move << '\n';
      return 0;
    }
    if(curr.k) //말처럼 아직 움직일 수 있는 경우
      for(int i=0; i<8; i++){
        int ny=curr.y+hy[i], nx=curr.x+hx[i];
        if(ny<0||nx<0||ny>=h||nx>=w) continue;
        if(discovered[ny][nx][curr.k-1] || adj[ny][nx]) continue;
        q.push(monkey(ny,nx,curr.k-1,curr.move+1));
        discovered[ny][nx][curr.k-1]=discovered[curr.y][curr.x][curr.k]+1;
      }
    for(int i=0; i<4; i++){
      int ny=curr.y+dy[i], nx=curr.x+dx[i];
      if(ny<0||nx<0||ny>=h||nx>=w) continue;
      if(discovered[ny][nx][curr.k] || adj[ny][nx]) continue;
      q.push(monkey(ny,nx,curr.k,curr.move+1));
      discovered[ny][nx][curr.k]=discovered[curr.y][curr.x][curr.k]+1;
    }
  }
  cout << -1 << '\n';
  return 0;
}

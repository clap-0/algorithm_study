#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct pos{ //현재 층 z와 행 y, 열 x
  int z, y, x;
  pos():z(-1),y(-1),x(-1) {}
  pos(int Z, int Y, int X) : z(Z), y(Y), x(X) {}
};
int l, r, c;
const int INF=987654321;
int dz[6]={0,0,0,0,1,-1},dy[6]={1,0,0,-1,0,0},dx[6]={0,1,-1,0,0,0};
char adj[30][30][30];
int shortestTime[30][30][30]; //각 칸으로 가는 최단시간 저장. INF로 초기화시킴
//BFS를 이용해 s칸에서 시작해서 탈출하는데 걸리는 최단시간을 구함
int bfs(pos& s){
  shortestTime[s.z][s.y][s.x]=0;
  queue<pos> q;
  q.push(s);
  while(!q.empty()){
    pos curr = q.front();
    q.pop();
    if(adj[curr.z][curr.y][curr.x]=='E') return shortestTime[curr.z][curr.y][curr.x];
    for(int i=0; i<6; i++){
      pos next(curr.z+dz[i], curr.y+dy[i], curr.x+dx[i]);
      if(next.z>=l||next.z<0||next.y>=r||next.y<0||next.x>=c||next.x<0) continue; //이동하려는 위치가 빌딩 바깥면인 경우
      if(adj[next.z][next.y][next.x]=='#') continue; //이동하려는 위치가 벽으로 막혀있는 경우
      if(shortestTime[next.z][next.y][next.x]==INF){ //아직 방문하지 않았다면 방문할 리스트에 추가
        q.push(next);
        shortestTime[next.z][next.y][next.x]=shortestTime[curr.z][curr.y][curr.x]+1;
      }
    }
  }
  return -1;
}
int main()
{
  while(1){
    cin >> l >> r >> c;
    if(l==0&&r==0&&c==0) break;
    int time;
    pos start;
    for(int i=0; i<l; i++){
      for(int j=0; j<r; j++){
        for(int k=0; k<c; k++){
          cin >> adj[i][j][k];
          if(adj[i][j][k]=='S') start=pos(i, j, k);
          shortestTime[i][j][k]=INF;
        }
      }
    }
    time = bfs(start);
    if(time!=-1) cout << "Escaped in "<< time <<" minute(s)." << endl;
    else cout << "Trapped!" << endl;
  }
  return 0;
}

#include <iostream>
#include <queue>
using namespace std;

const int MAX=3000;
const int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};

char adj[MAX][MAX];
bool discovered[MAX][MAX];

int main()
{
  int n, m, start;
  cin >> n >> m;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++){
      cin >> adj[i][j];
      if(adj[i][j]=='2') start=i*MAX+j;
    }
  //너비우선탐색
  int time=0;
  queue<int> q;
  discovered[start/MAX][start%MAX]=1;
  q.push(start);
  while(!q.empty()){
    int qsize=q.size();
    for(int i=0; i<qsize; i++){
      int y=q.front()/MAX, x=q.front()%MAX;
      q.pop();
      for(int i=0; i<4; i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue; //범위밖이면 패스
        if(discovered[ny][nx] || adj[ny][nx]=='1') continue; //이미 방문했거나 벽인 경우 패스
        discovered[ny][nx]=true;
        q.push(ny*MAX+nx);
        if(adj[ny][nx]!='0'){ //음식에 도달한 경우
          cout << "TAK\n" << time+1 << '\n';
          return 0;
        }
      }
    }
    time++;
  }
  cout << "NIE\n";
}

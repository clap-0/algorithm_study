#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int dy[4]={-1, 0, 0, 1}, dx[4]={0, -1, 1, 0};
vector<string> adj; //인접행렬
int discovered[100][100]; //discovered[i][j] = 시작위치(0, 0)에서 (i, j)까지 지나온 칸 수
int bfs(int y, int x) //(0, 0)에서 (n-1, m-1)로 이동할 때 지나야하는 최소의 칸 수 반환
{
  discovered[y][x] = 1; //시작위치도 칸 셀 때 포함
  queue<pair<int, int> > q; //방문할 칸(y, x) 저장
  q.push({y, x});
  while(!q.empty()){
    pair<int, int> here = q.front();
    q.pop();
    for(int i=0; i<4; i++){
      int ny=here.first+dy[i], nx=here.second+dx[i];
      if(ny==-1||ny==n||nx==-1||nx==m) continue;
      if(adj[ny][nx]=='1'&&!discovered[ny][nx]){
        discovered[ny][nx] = discovered[here.first][here.second]+1;
        q.push({ny, nx});
      }
    }
  }
  return discovered[n-1][m-1];
}
int main()
{
  cin >> n >> m;
  adj.resize(n);
  for(int i=0; i<n; i++)
    cin >> adj[i];
  cout << bfs(0, 0) << endl;
  return 0;
}

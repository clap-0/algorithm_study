#include <iostream>
#include <vector>
using namespace std;
int n, m;
int dy[4]={-1, 0, 0, 1}, dx[4]={0, -1, 1, 0}; //상하좌우
vector<vector<int> > adj; //인접행렬
vector<vector<int> > visited; //방문여부 저장
int dfs(int y, int x)
{
  int ret=1;
  visited[y][x] = true;
  for(int i=0; i<4; i++){
    int ny = y+dy[i], nx = x+dx[i];
    if(ny==-1||ny==n||nx==-1||nx==m) continue; //방문하려는 곳이 범위 밖일 경우
    if(adj[ny][nx]==0||visited[ny][nx]) continue; //방문하려는 곳에 쓰레기가 없거나 이미 방문한 경우
    ret += dfs(ny, nx);
  }
  return ret;
}
int main()
{
  int k, largest=0;
  cin >> n >> m >> k;
  adj.resize(n, vector<int>(m, 0));
  visited.resize(n, vector<int>(m, 0));
  for(int i=0; i<k; i++){
    int r, c;
    cin >> r >> c;
    adj[r-1][c-1] = true;
  }
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(adj[i][j]&&!visited[i][j]){
        largest = max(largest, dfs(i, j));
      }
  cout << largest << endl;
  return 0;
}

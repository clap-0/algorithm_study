#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m, n;
int dy[4]={-1, 0, 0, 1}, dx[4]={0, -1, 1, 0};
vector<vector<bool> >adj; //인접행렬 및 방문가능여부저장
vector<int> area; //각 영역의 넓이 저장
int dfs(int y, int x) //y,x와 연결된 영역의 넓이 반환
{
  int ret=1;
  adj[y][x] = false; //방문한 곳은 더이상 방문 불가
  for(int i=0; i<4; i++){
    int ny=y+dy[i], nx=x+dx[i];
    if(ny==-1||ny==m||nx==-1||nx==n) continue;
    if(adj[ny][nx]) ret += dfs(ny, nx);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int k, cnt=0;
  cin >> m >> n >> k;
  adj.resize(m, vector<bool>(n, true));
  for(int cnt=0; cnt<k; cnt++){ //직사각형 내부영역 방문불가
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i=y1; i<y2; i++)
      for(int j=x1; j<x2; j++)
        adj[i][j] = false;
  }
  for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)
      if(adj[i][j]){
        area.push_back(dfs(i, j));
        cnt++;
      }
  sort(area.begin(), area.end());
  cout << cnt << endl;
  for(int i=0; i<area.size(); i++) cout << area[i] << ' ';
  return 0;
}

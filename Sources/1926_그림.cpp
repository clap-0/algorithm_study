#include <iostream>
using namespace std;
int n, m;
int dy[4]={-1, 0, 0, 1}, dx[4]={0, -1, 1, 0};
int colored[500][500]; //그림의 정보 저장
int visited[500][500]; //해당 위치에 방문했는지 저장
int dfs(int y, int x) //y,x와 이어진 색칠된 부분의 넓이 반환
{
  int ret = 1;
  visited[y][x] = true;
  for(int cnt=0; cnt<4; cnt++){
    int ny = y+dy[cnt], nx = x+dx[cnt];
    if(ny==-1||ny==n||nx==-1||nx==m) continue;
    if(visited[ny][nx]) continue;
    if(colored[ny][nx]) ret+=dfs(ny, nx);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int picN=0, largest=0; //그림의 수와 최대 넓이 저장
  cin >> n >> m;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin >> colored[i][j];
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(colored[i][j]&&!(visited[i][j])){
        picN++;
        largest = max(largest, dfs(i, j));
      }
  cout << picN << '\n' << largest << '\n';
  return 0;
}

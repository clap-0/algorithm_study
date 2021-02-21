#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
int dy[4]={-1, 0, 0, 1}, dx[4]={0, -1, 1, 0}; //상하좌우
vector<vector<bool> > seen; //해당위치를 확인했는지 저장
vector<vector<bool> > cabbage; //배추의 위치저장
void dfs(int y, int x)
{
  seen[y][x] = true;
  for(int i=0; i<4; i++){
    int ny=y+dy[i], nx=x+dx[i];
    if(ny==-1||ny==n||nx==-1||nx==m) continue;
    if(!(cabbage[ny][nx])||seen[ny][nx]) continue;
    dfs(ny, nx);
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int x, y, worm=0;
    cin >> m >> n >> k;
    seen = cabbage = vector<vector<bool> >(n, vector<bool>(m, 0));
    for(int i=0; i<k; i++){
      cin >> x >> y;
      cabbage[y][x] = true;
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(cabbage[i][j]&&!(seen[i][j])){
          dfs(i, j);
          worm++;
        }
      }
    }
    cout << worm << endl;
  }
  return 0;
}

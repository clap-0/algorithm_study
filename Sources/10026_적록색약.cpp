#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
int dy[4]={-1, 0, 0, 1}, dx[4]={0, -1, 1, 0};
vector<string> adj; //인접행렬
vector<vector<bool> > visited; //방문여부 저장
void dfs(int y, int x, bool colorBlindness)
{
  visited[y][x]=true;
  for(int i=0; i<4; i++){
    int ny = y+dy[i], nx = x+dx[i];
    if(ny==-1||ny==n||nx==-1||nx==n) continue; //범위 밖이면 패스
    if(visited[ny][nx]) continue; //이미 방문한 곳이면 패스
    char here=adj[y][x], there=adj[ny][nx]; //현재 위치의 색과 방문하려는 위치의 색 저장
    if(here==there) //색이 같으면 방문
      dfs(ny, nx, colorBlindness);
    else if(colorBlindness&&abs(here-there)=='R'-'G') //적록색약이고 현위치와 방문하려는 위치가 빨강과 초록이면 방문
      dfs(ny, nx, colorBlindness);
  }
}
int main()
{
  vector<int> area(2, 0); //적록색약이 아닌사람의 구역 수와 적록색약의 구역 수 저장
  cin >> n;
  adj.resize(n);
  for(int i=0; i<n; i++)
    cin >> adj[i];
  for(int isBlind=0; isBlind<2; isBlind++){
    visited.clear(); visited.resize(n, vector<bool>(n, false)); //방문여부 초기화
    for(int i=0; i<n; i++)
     for(int j=0; j<n; j++)
        if(!visited[i][j]){
         dfs(i, j, isBlind);
         area[isBlind]++;
        }
  }
  cout << area[0] << ' ' << area[1] << endl;
  return 0;
}

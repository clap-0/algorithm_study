#include <iostream>
using namespace std;
int N;
int map[64][64];
bool visited[64][64];
// 깊이우선탐색 알고리즘
bool dfs(int y, int x){
  visited[y][x]=true;
  // 목적지에 도착한 경우 true 반환
  if(y==N-1&&x==N-1) return true;
  bool ret=false;
  for(int i=0; i<2; i++){
    int ny=y+map[y][x]*i, nx=x+map[y][x]*(1-i);
    if(ny>=N||nx>=N||visited[ny][nx]) continue;
    ret|=dfs(ny, nx);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) cin >> map[i][j];
  cout << (dfs(0,0) ? "HaruHaru" : "Hing") << '\n';
}

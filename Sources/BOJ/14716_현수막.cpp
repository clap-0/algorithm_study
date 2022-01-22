#include <iostream>
using namespace std;

int M, N;
bool banner[250][250];
const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 깊이우선탐색
void dfs(int y, int x) {
  banner[y][x] = false;
  for(int i=0; i<8; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if(ny<0 || nx<0 || ny>=M || nx>=N || !banner[ny][nx]) continue;
    dfs(ny, nx);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> M >> N;
  for(int i=0; i<M; i++) 
    for(int j=0; j<N; j++) 
      cin >> banner[i][j];
  
  // 컴포넌트의 개수를 구한다
  int ans = 0;
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++)
      if(banner[i][j]) {
        dfs(i, j);
        ++ans;
      }
  
  cout << ans << '\n';
}

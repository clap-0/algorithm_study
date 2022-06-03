#include <iostream>
#include <cstring>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

int H, W;
bool adj[100][100]; // 인접행렬
bool visited[100][100];

// 그리드에서 깊이우선탐색 수행
void dfs(int y, int x) {
  visited[y][x] = true;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
    if(!visited[ny][nx] && adj[ny][nx]) dfs(ny, nx);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    cin >> H >> W;
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++) {
        char ch;
        cin >> ch;
        adj[i][j] = ch == '#';
      }
    
    memset(visited, false, sizeof(visited));
    int components = 0; // 컴포넌트의 개수
    for(int i = 0; i < H; i++)
      for(int j = 0; j < W; j++)
        if(!visited[i][j] && adj[i][j]) {
          dfs(i, j);
          ++components;
        }
    cout << components << '\n';
  }
}

#include <iostream>
using namespace std;

int N, M;
int height[100][70];  // 각 격자의 높이
bool visited[100][70];  // 각 격자의 방문여부

// x좌표 차이와 y좌표 차이 모두 1 이하인 경우 인접하다
const int dy[8] = {-1,-1,0,1,1,1,0,-1}, dx[8] = {0,1,1,1,0,-1,-1,-1};

// y행 x열 격자와 인접한 높이가 같은 격자들을 깊이우선탐색으로 방문한다
// 탐색 중 인접한 격자의 높이가 더 높은 경우 false를, 그러한 격자가 없는 경우 true를 반환한다
bool dfs(int y, int x) {
  visited[y][x] = true;
  bool isTop = true;
  for(int i = 0; i < 8; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
    if(!visited[ny][nx] && height[ny][nx] == height[y][x]) isTop &= dfs(ny, nx);
    else if(height[ny][nx] > height[y][x]) isTop = false;
  }
  return isTop;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) cin >> height[i][j];

  int peaks = 0;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      if(!visited[i][j] && dfs(i, j)) ++peaks;
  cout << peaks << '\n';
}

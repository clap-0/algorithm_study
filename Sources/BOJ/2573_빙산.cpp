#include <iostream>
#include <cstring>
using namespace std;

const int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int N, M;
int height[300][300];
bool visited[300][300];

// 깊이우선탐색을 사용해 y행 x열의 높이를 줄이고, 붙어있는 다른 빙산들의 높이도 줄인다.
void dfs(int y, int x) {
  visited[y][x] = true;
  for(int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    
    // 범위의 밖이거나 이미 방문한 부분인 경우 넘긴다
    if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
    
    if(height[ny][nx]) dfs(ny, nx); // ny행 nx열이 빙산이면 해당 부분에서 줄어드는 높이를 구한다.
    else height[y][x] = max(0, height[y][x] - 1); // 바닷물이면 현재 부분의 높이를 줄인다.
  }
}

// 빙산이 두 덩어리로 나누어지는데 걸리는 시간을 반환한다. 모두 녹을 때까지 한 덩어리라면 0을 반환
int getThawedTime() {
  int times = 0;
  while(true) {
    bool foundOneMass = false;  // 이번 년도에서 빙산 한 덩어리를 찾았는지 여부
    memset(visited, false, sizeof(visited));  // 각 부분의 방문여부를 false로 초기화한다.
    
    // 이번 년도에 방문하지 않은 빙산을 찾아 해당 빙산의 높이를 줄인다.
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
        if(height[i][j] && !visited[i][j]) {
          if(foundOneMass) return times;  // 이번 년도에 이미 빙산 한 덩어리를 찾은 경우 빙산이 두 덩어리 이상이므로 시간을 반환한다.
          foundOneMass = true;
          dfs(i, j);
        }
    
    // 빙산이 없는 경우 반복문 종료
    if(!foundOneMass) break;
    ++times;
  }
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) cin >> height[i][j];

  cout << getThawedTime() << '\n';
}

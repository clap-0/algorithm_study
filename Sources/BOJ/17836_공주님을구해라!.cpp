#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

int castle[100][100]; // 성의 구조
bool visited[100][100]; // 각 칸의 방문여부

// 넓이우선탐색을 이용하여 공주가 있는 방까지 가는데에 걸리는 최소시간을 구한다
int bfs(int N, int M) {
  int ret = 10001;
  queue<pair<int,int> > Q;
  Q.push({0, 0});
  visited[0][0] = true;

  int times = 0;
  while(!Q.empty()) {
    int qsize = Q.size();
    while(qsize--) {
      int y = Q.front().first, x = Q.front().second;
      Q.pop();

      // 공주가 있는 칸에 도착한 경우, 그람 없이 걸린 시간과 그람을 통해 걸린 시간 중 짧은 시간 반환
      if(y + 1 == N && x + 1 == M) {
        return min(ret, times);
      }
      // 그람이 있는 칸에 도착한 경우, 현재 칸에서 공주가 있는 칸까지 모든 벽을 부수며 갈 때 최소시간을 구한다
      else if(castle[y][x] == 2) ret = times + (N - 1 - y) + (M - 1 - x);

      // 상하좌우로 이동
      for(int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;  // 범위 밖인 경우 패스
        if(!visited[ny][nx] && castle[ny][nx] != 1) { // 아직 방문하지 않았고, 벽이 아닌 경우 이동
          Q.push({ny, nx});
          visited[ny][nx] = true;
        }
      }
    }
    ++times;
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M, T;
  cin >> N >> M >> T;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) cin >> castle[i][j];

  int ans = bfs(N, M);
  if(ans <= T) cout << ans << '\n';
  else cout << "Fail\n";
}

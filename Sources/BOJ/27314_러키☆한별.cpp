#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, -1, 0, 1};

int N, M;
// 시간 및 공간 복잡도를 줄이기 위해, 매 getGiftCnt() 함수 실행마다 방문 확인을 위해
// visited 배열을 초기화하는 대신, maze 배열을 tmp 배열로 복사해서 사용한다.
vector<string> tmp;
vector<string> maze;

// 출구의 위치가 {sr,sc} 일 때, 한별이가 얻을 수 있는 선물 개수를 반환한다.
int getGiftCnt(int sr, int sc)
{
  queue<pair<int,int> > Q;
  Q.push({sr, sc});
  tmp[sr][sc] = 'X';

  // 너비우선탐색
  int ret = 0;
  while (!Q.empty()) {
    bool hasReached = false;
    int qsize = Q.size();
    while (qsize--) {
      int row = Q.front().first, col = Q.front().second;
      Q.pop();

      for (int i = 0; i < 4; i++) {
        int nr = row + dr[i], nc = col + dc[i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= M || tmp[nr][nc] == 'X') {
          continue;
        }

        if (tmp[nr][nc] == 'P') { // 출구에서 다른 사람까지의 최단거리가 한별이보다 작거나 같은 경우
          ++ret;
        }
        else if (tmp[nr][nc] == 'H') {  // 출구에서 한별이까지의 최단경로를 구한 경우
          hasReached = true;
        }

        tmp[nr][nc] = 'X';
        Q.push({nr, nc});
      }
    }

    // 출구에서 한별이까지의 최단경로를 구한 경우, 그보다 거리가 작거나 같은 사람 수를 반환한다.
    if (hasReached) {
      return ret;
    }
  }
  
  // 한별이가 출구에 도달할 수 없는 경우 0을 반환한다.
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;

  maze = vector<string>(N);

  for (int i = 0; i < N; i++) {
    cin >> maze[i];
  }
  
  int ans = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (maze[i][j] == '#') {
        tmp = maze; // 방문 여부 확인을 위해 maze 배열을 복사해 tmp 배열을 사용한다.
        ans = max(ans, getGiftCnt(i, j));
      }

  cout << ans << '\n';
}

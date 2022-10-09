#include <iostream>
using namespace std;

const int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
int R, C, K;
bool obstacles[5][5];
bool visited[5][5];

int getWays(int r, int c, int dist)
{
  if (r == 0 && c == C - 1) 
    return (dist == K ? 1 : 0);
  int ret = 0;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= R || nc >= C || obstacles[nr][nc])
      continue;
    if (!visited[nr][nc]) {
      visited[nr][nc] = true;
      ret += getWays(nr, nc, dist + 1);
      visited[nr][nc] = false;
    }
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  cin >> R >> C >> K;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      char ch;
      cin >> ch;
      obstacles[i][j] = (ch == 'T');
    }

  visited[R - 1][0] = true;
  cout << getWays(R - 1, 0, 1) << '\n';
}

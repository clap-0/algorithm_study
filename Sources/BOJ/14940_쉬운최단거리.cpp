#include <iostream>
#include <queue>
using namespace std;

int board[1000][1000];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  pair<int,int> target;
  
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) {
        board[i][j] = -1;
      }
      else if (board[i][j] == 2) {
        target = {i, j};
        board[i][j] = -1;
      }
    }
  }

  queue<pair<int, int> > Q;
  Q.push({target.first, target.second});
  board[target.first][target.second] = 0;

  while (!Q.empty()) {
    int y = Q.front().first, x = Q.front().second;
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= m || board[ny][nx] != -1) {
        continue;
      }
      Q.push({ny, nx});
      board[ny][nx] = board[y][x] + 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
}

#include <iostream>

using namespace std;

int M, N;
bool fabric[1000][1000];
bool visited[1000][1000];

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

void dfs(int y, int x)
{
  visited[y][x] = true;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= M || nx >= N || visited[ny][nx]) continue;
    if (!fabric[ny][nx]) {
      visited[ny][nx] = true;
      dfs(ny, nx);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> M >> N;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      char ch;
      cin >> ch;
      fabric[i][j] = (ch == '1');
    }
  }

  for (int i = 0; i < N; i++) {
    dfs(0, i);
  }

  bool ans = false;
  for (int i = 0; i < N; i++) 
    if (visited[M - 1][i]) {
      ans = true;
      break;
    }

  cout << (ans ? "YES\n" : "NO\n");
}
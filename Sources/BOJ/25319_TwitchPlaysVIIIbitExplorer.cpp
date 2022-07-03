#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
char board[50][50];
bool visited[50][50];
bool picked[50][50];
char record[1500000];

void updateRecord(int yOffset, int xOffset, int& L)
{
  if(yOffset > 0)
    for(int i = 0; i < yOffset; i++)
      record[L++] = 'D';
  else
    for(int i = 0; i < -yOffset; i++)
      record[L++] = 'U';
  if(xOffset > 0)
    for(int i = 0; i < xOffset; i++)
      record[L++] = 'R';
  else
    for(int i = 0; i < -xOffset; i++)
      record[L++] = 'L';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M, len;
  string S;
  cin >> N >> M >> len;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> board[i][j];
  cin >> S;
  
  int C = 0, L = 0, tempL = 0, iter = 0;
  pair<int,int> lastPicked = {0, 0}, lastEnforced = {0, 0};
  queue<pair<int,int> > Q;
  Q.push({0, 0});
  visited[0][0] = true;
  while (!Q.empty())
  {
    int y = Q.front().first, x = Q.front().second;
    Q.pop();
    if (board[y][x] == S[iter] && !picked[y][x])
    {
      picked[y][x] = true;
      memset(visited, false, sizeof(visited));
      visited[y][x] = true;
      Q = {};

      updateRecord(y - lastPicked.first, x - lastPicked.second, tempL);
      record[tempL++] = 'P';
      lastPicked = {y, x};

      if ((++iter %= len) == 0)
      {
        ++C;
        L = tempL;
        lastEnforced = lastPicked;
      }
    }

    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i], nx = x + dx[i];
      if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
      Q.push({ny, nx});
      visited[ny][nx] = true;
    }
  }

  updateRecord(N - 1 - lastEnforced.first, M - 1 - lastEnforced.second, L);

  cout << C << ' ' << L << '\n';
  for(int i = 0; i < L; i++)
    cout << record[i];
}

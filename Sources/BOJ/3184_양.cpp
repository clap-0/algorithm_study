#include <iostream>
using namespace std;

const int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};

int R, C;
char backyard[250][250];
bool visited[250][250];

void countAnimals(int r, int c, int& sheep, int& wolves)
{
  visited[r][c] = true;
  if (backyard[r][c] == 'o')
      ++sheep;
    else if (backyard[r][c] == 'v')
      ++wolves;
  for (int i = 0; i < 4; i++)
  {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= R || nc >= C || visited[nr][nc])
      continue;
    if (backyard[nr][nc] != '#')
      countAnimals(nr, nc, sheep, wolves);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> R >> C;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      cin >> backyard[i][j];

  int sheepLeft = 0, wolvesLeft = 0;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (!visited[i][j] && backyard[i][j] != '#')
      {
        int sheep = 0, wolves = 0;
        countAnimals(i, j, sheep, wolves);
        if (sheep <= wolves)
          wolvesLeft += wolves;
        else
          sheepLeft += sheep;
      }

  cout << sheepLeft << ' ' << wolvesLeft << '\n';
}

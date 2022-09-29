#include <iostream>
using namespace std;

int n, m;
char floorDeco[50][50];
bool visited[50][50];

void dfs(int r, int c)
{
  visited[r][c] = true;
  if (floorDeco[r][c] == '-') {
    if (c + 1 < m && floorDeco[r][c + 1] == '-' && !visited[r][c + 1])
      dfs(r, c + 1);
  } 
  else {
    if (r + 1 < n && floorDeco[r + 1][c] == '|' && !visited[r + 1][c])
      dfs(r + 1, c);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> floorDeco[i][j];

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!visited[i][j]) {
        dfs(i, j);
        ++ans;
      }
  cout << ans << '\n';
}

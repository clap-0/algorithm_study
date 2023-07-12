#include <iostream>
#include <unordered_set>
using namespace std;

const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, -1, 0, 1};

string digits[5][5];
unordered_set<string> us;

void dfs(int r, int c, string str) {
  if (str.length() == 6) {
    us.insert(str);
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5)
      continue;
    dfs(nr, nc, str + digits[nr][nc]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      cin >> digits[i][j];

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      dfs(i, j, digits[i][j]);

  cout << us.size() << '\n';
}

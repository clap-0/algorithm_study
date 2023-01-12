#include <iostream>
using namespace std;

const int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dc[8] = {0, -1, -1, -1, 0, 1, 1, 1};
char letter[200][200];  // 단어 격자
long long dp[200][200][2];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int H, W, L;
  string word;
  cin >> H >> W >> L;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      cin >> letter[i][j];
  cin >> word;

  // 주어진 단어의 첫 글자와 일치하는 알파벳이 있는 인덱스의 dp를 1로 초기화한다.
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      if (letter[i][j] == word[0])
        dp[i][j][0] = 1;
  
  for (int l = 1; l < L; l++) // l : 주어진 단어의 인덱스
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++)
        if (letter[i][j] == word[l]) {  // 단어의 l번째 글자와 일치하는 단어격자의 위치에서
          dp[i][j][l % 2] = 0;          // 인접한 위치의 (l-1)번째 글자와 일치하는 인덱스의 dp값을 더한다.
          for (int d = 0; d < 8; d++) {
            int nr = i + dr[d], nc = j + dc[d];
            if (nr < 0 || nc < 0 || nr >= H || nc >= W)
              continue;
            if (letter[nr][nc] == word[l - 1])
              dp[i][j][l % 2] += dp[nr][nc][(l - 1) % 2];
          }
        }

  long long ans = 0LL;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      if (letter[i][j] == word[L - 1])
        ans += dp[i][j][(L - 1) % 2];
  
  cout << ans << '\n';
}

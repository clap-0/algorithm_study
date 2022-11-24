#include <iostream>
using namespace std;

int N, M;
int ans[8];
bool visited[8];

void backtracking(int cnt)
{
  if (cnt == M) {
    for (int i = 0; i < M; i++)
      cout << ans[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = 0; i < N; i++)
    if (!visited[i]) {
      visited[i] = true;
      ans[cnt] = i + 1;
      backtracking(cnt + 1);
      visited[i] = false;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  backtracking(0);
}

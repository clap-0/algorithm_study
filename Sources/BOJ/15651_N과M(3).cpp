#include <iostream>
using namespace std;

int N, M;
int ans[7];

void backtracking(int cnt)
{
  if (cnt == M) {
    for (int i = 0; i < M; i++)
      cout << ans[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = 0; i < N; i++) {
      ans[cnt] = i + 1;
      backtracking(cnt + 1);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  backtracking(0);
}

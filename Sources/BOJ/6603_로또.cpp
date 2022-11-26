#include <iostream>
using namespace std;

int N;
int arr[12], ans[6];

void backtracking(int idx, int cnt)
{
  if (cnt == 6) {
    for (int i = 0; i < 6; i++)
      cout << ans[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = idx + 1; i < N; i++) {
    ans[cnt] = arr[i];
    backtracking(i, cnt + 1);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while (true) {
    cin >> N;
    if (N == 0)
      break;
    for (int i = 0; i < N; i++)
      cin >> arr[i];
    backtracking(-1, 0);
    cout << '\n';
  }
}

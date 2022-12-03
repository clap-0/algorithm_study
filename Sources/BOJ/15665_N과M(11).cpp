#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[7];
int ans[7];

void backtracking(int cnt)
{
  if (cnt == M) {
    for (int i = 0; i < M; i++)
      cout << ans[i] << ' ';
    cout << '\n';
    return;
  }
  int prev = -1;
  for (int i = 0; i < N; i++)
    if (arr[i] != prev) {
      prev = ans[cnt] = arr[i];
      backtracking(cnt + 1);
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> arr[i];
  sort(arr, arr + N);
  backtracking(0);
}

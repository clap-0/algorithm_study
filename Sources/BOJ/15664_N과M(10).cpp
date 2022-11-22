#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9], result[9];

void solve(int idx, int cnt)
{
  if (cnt == m) {
    for (int i = 0; i < m; i++)
      cout << result[i] << ' ';
    cout << '\n';
    return;
  }
  int prev = -1;
  for (int i = idx + 1; i <= n; i++)
    if (prev != arr[i]) {
      result[cnt] = arr[i];
      solve(i, cnt + 1);
      prev = arr[i];
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  
  sort(arr, arr + n + 1);

  solve(0, 0);
}

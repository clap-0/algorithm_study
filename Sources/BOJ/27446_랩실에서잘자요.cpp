#include <iostream>
using namespace std;

bool isFound[101];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int page;
    cin >> page;
    isFound[page] = true;
  }

  int ans = 0;

  int prev = -1, sum = 0;
  for (int i = 1; i <= n; i++)
    if (!isFound[i]) {
      if (prev == -1 || 2 * (i - prev) > 7) {
        ans += sum;
        sum = 7;  // 5 + 2*1
      }
      else {
        sum += 2 * (i - prev);
      }
      prev = i;
    }
  
  cout << (ans += sum) << '\n';
}

#include <iostream>
using namespace std;
const int MAX = 1024;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  int psum[MAX + 1][MAX + 1] = {0};
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> psum[i][j];
      psum[i][j] += (psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1]);
    }
  while (m--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << psum[y2][x2] - psum[y2][x1 - 1] - psum[y1 - 1][x2] + psum[y1 - 1][x1 - 1] << '\n';
  }
  return 0;
}

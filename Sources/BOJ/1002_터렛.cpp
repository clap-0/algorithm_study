#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int T;
  cin >> T;
  while (T--) {
    int x[2], y[2], r[2];
    for (int i = 0; i < 2; i++)
      cin >> x[i] >> y[i] >> r[i];

    int dist = pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2);
    int cond1 = pow(r[0] - r[1], 2), cond2 = pow(r[0] + r[1], 2);
    if (dist == 0)
      cout << (cond1 != 0 ? 0 : -1) << '\n';
    else if (dist == cond1 || dist == cond2)
      cout << 1 << '\n';
    else if (cond1 < dist && dist < cond2)
      cout << 2 << '\n';
    else
      cout << 0 << '\n';
  }
}

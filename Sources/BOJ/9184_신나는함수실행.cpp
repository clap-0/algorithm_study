#include <iostream>
using namespace std;

int cache[21][21][21];

int w(int a, int b, int c)
{
  if (a <= 0 || b <= 0 || c <= 0) {
    return 1;
  }

  int& ret = cache[a][b][c];
  if (ret != 0) return ret;

  if (a < b && b < c) {
    ret = w(a, b, c - 1);
    ret += w(a, b - 1, c - 1);
    ret -= w(a, b - 1, c);
  }
  else {
    ret = w(a - 1, b, c);
    ret += w(a - 1, b - 1, c);
    ret += w(a - 1, b, c - 1);
    ret -= w(a - 1, b - 1, c - 1);
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while (true) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1) {
      break;
    }

    int ans;
    if (a <= 0 || b <= 0 || c <= 0) {
      ans = 1;
    }
    else if (a > 20 || b > 20 || c > 20) {
      ans = w(20, 20, 20);
    }
    else {
      ans = w(a, b, c);
    }
    cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
  }
}

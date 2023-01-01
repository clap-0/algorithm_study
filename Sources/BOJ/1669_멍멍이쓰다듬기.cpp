#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  unsigned int x, y;
  cin >> x >> y;
  unsigned int diff = y - x;
  if (diff == 0)
    cout << 0 << '\n';
  else {
    int cnt = 0;
    while (cnt * cnt < diff)
      ++cnt;
    cout << (cnt * cnt - cnt < diff ? cnt * 2 - 1 : cnt * 2 - 2) << '\n';
  }
}

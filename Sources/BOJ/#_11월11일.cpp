#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  const int days[13] = {31,31,28,31,30,31,30,31,31,30,31,30,31};
  cin >> T;
  while(T--) {
    int y, m;
    cin >> y >> m;
    if(m == 3) {
      bool isLeapYear = (y % 4 == 0 && y % 100) || (y % 400 == 0);
      cout << y << ' ' << 2 << ' ' << days[2] + isLeapYear << '\n';
    }
    else {
      cout << (m != 1 ? y : y - 1) << ' ';
      cout << (m + 10) % 12 + 1 << ' ' << days[m - 1] << '\n';
    }
  }
}

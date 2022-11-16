#include <iostream>
using namespace std;

const int coins[4] = {25, 10, 5, 1};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < 4; i++) {
      cout << n / coins[i] << ' ';
      n %= coins[i];
    }
    cout << '\n';
  }
}

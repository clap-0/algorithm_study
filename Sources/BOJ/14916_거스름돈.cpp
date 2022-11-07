#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  
  int five = n / 5;
  int remaining = (n - five * 5) % 2;
  while (remaining != 0) {
    if (five == 0) {
        cout << -1 << '\n';
        return 0;
    }
    --five;
    remaining = (n - five*5) % 2;
  }
  cout << five + (n - five * 5) / 2 << '\n';
}

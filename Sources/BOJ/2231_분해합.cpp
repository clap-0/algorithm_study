#include <iostream>
using namespace std;

int decomposeSum(int n)
{
  int ret = n;
  while (n) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    if (decomposeSum(i) == n) {
      cout << i << '\n';
      return 0;
    }
  cout << 0 << '\n';
}

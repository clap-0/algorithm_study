#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  int m = (n & 1 ? n - 1 : n);
  for (int i = 0; i < m; i++)
    cout << 1 + (i % 2) << ' ';
  if (n & 1)
    cout << 3 << '\n';
}

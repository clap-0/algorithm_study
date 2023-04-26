#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int A, B, C;
  while (cin >> A >> B >> C) {
    cout << max(B - A - 1, C - B - 1) << '\n';
  }
}

#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int A, B, C;
  cin >> A >> B >> C;
  cout << (B < C ? (A / (C - B)) + 1 : -1) << '\n';
}

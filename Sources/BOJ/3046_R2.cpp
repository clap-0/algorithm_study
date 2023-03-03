#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int R1, R2, S;
  cin >> R1 >> S;
  R2 = 2 * S - R1;
  cout << R2 << '\n';
}

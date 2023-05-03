#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int A, I;
  cin >> A >> I;
  cout << A * (I - 1) + 1 << '\n';
}

#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while (true) {
    int A, B;
    cin >> A >> B;
    if (A == 0)
      break;
    cout << (A > B ? "Yes\n" : "No\n");
  }
}

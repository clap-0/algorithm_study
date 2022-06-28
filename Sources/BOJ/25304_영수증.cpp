#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int X, N, a, b, Y = 0;
  cin >> X >> N;
  for(int i = 0; i < N; i++) {
    cin >> a >> b;
    Y += a * b;
  }
  cout << (X == Y ? "Yes" : "No") << '\n';
}

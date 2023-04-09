#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  int ans = 0, toEat = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int milk;
    cin >> milk;
    if (milk == toEat) {
      ++ans;
      toEat = (toEat + 1) % 3;
    }
  }

  cout << ans << '\n';
}

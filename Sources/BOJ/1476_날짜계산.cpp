#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

  int e, s, m;
  cin >> e >> s >> m;

  int ans = 1;
  while(true) {
      if ((ans-e) % 15 == 0 && (ans-s) % 28 == 0 && (ans-m) % 19 == 0) {
        break;
      }
    ++ans;
  }

  cout << ans << '\n';
}

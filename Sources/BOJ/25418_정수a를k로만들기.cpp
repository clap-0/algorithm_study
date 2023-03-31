#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int A, K;
  cin >> A >> K;

  int ans = 0;
  while (A < K) {
    if (!(K & 1) && (K >> 1) >= A) {
      K >>= 1;
    }
    else {
      --K;
    }
    ++ans;
  }

  cout << ans << '\n';
}

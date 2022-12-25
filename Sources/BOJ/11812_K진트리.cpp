#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  long long N;
  int K, Q;
  cin >> N >> K >> Q;
  while (Q--) {
    long long x, y;
    cin >> x >> y;
    if (K == 1)
      cout << abs(x - y) << '\n';
    else {
      int dist = 0;
      while (x != y) {
        while (x > y) {
          dist++;
          x = (x + K - 2) / K;
        }
        while (x < y) {
          dist++;
          y = (y + K - 2) / K;
        }
      }
      cout << dist << '\n';
    }
  }
}

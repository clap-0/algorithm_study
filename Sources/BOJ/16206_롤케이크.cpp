#include <iostream>
#include <algorithm>
using namespace std;

int length[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;

  int ans = 0;
  for (int i = 0; i < N; i++)
    cin >> length[i];

  sort(length, length + N, [](const int &a, const int &b){
    if (a % 10 | b % 10)
      return a % 10 < b % 10;
    return a < b;
  });

  for (int i = 0; i < N && M > 0; i++) {
    if (length[i] % 10) {
      int cost = min(M, length[i] / 10);
      ans += cost;
      M -= cost;
    }
    else {
      int cost = length[i] / 10 - 1;
      if (cost <= M) {
        ans += cost + 1;
        M -= cost;
      }
      else {
        ans += M;
        M -= cost;
      }
    }
  }

  cout << ans << '\n';
}

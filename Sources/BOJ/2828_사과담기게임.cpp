#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M, J;
  cin >> N >> M >> J;

  int ans = 0;
  int left = 1, right = M;
  for (int i = 0; i < J; i++) {
    int pos;
    cin >> pos;
    if (pos < left) {
      ans += left - pos;
      left = pos;
      right = left + M - 1;
    }
    else if (right < pos) {
      ans += pos - right;
      right = pos;
      left = right - M + 1;
    }
  }
  cout << ans << '\n';
}

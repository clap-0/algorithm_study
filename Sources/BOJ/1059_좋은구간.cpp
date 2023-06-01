#include <iostream>
#include <algorithm>
using namespace std;

int S[50];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int L, n;
  cin >> L;
  for (int i = 0; i < L; i++) {
    cin >> S[i];
  }
  cin >> n;

  sort(S, S + L);
  int ans = 0;
  int hi = lower_bound(S, S + L, n) - S;

  if (S[hi] != n) {
    int left = (hi > 0 ? S[hi - 1] + 1 : 1);
    int right = S[hi] - 1;
    ans = (n - left) * (right - n + 1) + (right - n);
  }

  cout << ans << '\n';
}

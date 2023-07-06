#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string S;
  cin >> S;
  int len = S.length();

  int ans = 0;
  for (int i = 0; i < len; i++) {
    int j = 0;
    int k = (len - i) / 2;
    while (j < k && S[j + i] == S[len - j - 1]) {
      ++j;
    }
    if (j == k) {
      ans = len + i;
      break;
    }
  }

  cout << ans << '\n';
}

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string S;
  cin >> S;
  sort(S.begin(), S.end());
  int len = S.length(), ans = 0;
  do {
    bool isLucky = true;
    for (int i = 1; i < len; i++)
      if (S[i - 1] == S[i]) {
        isLucky = false;
        break;
      }
    if (isLucky) ++ans; 
  } while (next_permutation(S.begin(), S.end()));

  cout << ans << '\n';
}

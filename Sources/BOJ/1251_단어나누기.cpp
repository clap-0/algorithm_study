#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string str;
  cin >> str;
  int len = str.length();
  string ans = string(len, 'z');
  for (int i = 1; i < len; i++) {
    reverse(str.begin(), str.begin() + i);
    for (int j = i + 1; j < len; j++) {
      reverse(str.begin() + i, str.begin() + j);
      reverse(str.begin() + j, str.end());
      ans = min(ans, str);
      reverse(str.begin() + i, str.begin() + j);
      reverse(str.begin() + j, str.end());
    }
    reverse(str.begin(), str.begin() + i);
  }
  cout << ans << '\n';
}

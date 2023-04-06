#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string str;
  cin >> str;

  int cnt[2] = {0};
  for (int i = 0; i < str.length(); i++) {
    cnt[str[i] - '0']++;
  }
  
  cnt[0] >>= 1;
  cnt[1] >>= 1;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '0') {
      if (cnt[0]) {
        cnt[0]--;
        cout << '0';
      }
    }
    else {
      if (cnt[1]) {
        cnt[1]--;
      }
      else {
        cout << '1';
      }
    }
  }
}

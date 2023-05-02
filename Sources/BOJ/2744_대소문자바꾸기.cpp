#include <iostream>
using namespace std;


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string str;
  cin >> str;
  for (char ch : str) {
    if ('A' <= ch && ch <= 'Z') {
      cout << char(ch + 32);
    }
    else {
      cout << char(ch - 32);
    }
  }
}

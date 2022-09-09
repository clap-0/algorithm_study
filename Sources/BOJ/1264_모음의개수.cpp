#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string str;
  while(true) {
    getline(cin, str);
    if(str[0] == '#') break;
    int cnt = 0;
    for (char ch : str) {
      switch(ch) {
        case 'A': case 'a':
        case 'E': case 'e':
        case 'I': case 'i':
        case 'O': case 'o':
        case 'U': case 'u':
        ++cnt;
        break;
        default: ;
      }
    }
    cout << cnt << '\n';
  }
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string str;
  getline(cin, str);

  const string UCPC = "UCPC";
  int i = 0;
  for(char ch : str)
    if(ch == UCPC[i] && ++i == 4) break;
  cout << "I " << (i == 4 ? "love" : "hate") << " UCPC\n";
}

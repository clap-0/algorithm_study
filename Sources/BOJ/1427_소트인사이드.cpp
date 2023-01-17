#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string str;
  cin >> str;
  sort(str.begin(), str.end(), greater<char>());
  cout << str << '\n';
}

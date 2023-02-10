#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int underbars = 0;
  string emoji;
  cin >> emoji;
  for (char ch : emoji)
    if (ch == '_') ++underbars;
  
  cout << emoji.size() + 2 + underbars * 5 << '\n';
}

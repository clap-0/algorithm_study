#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int ans = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      char piece;
      cin >> piece;
      if (piece == 'F' && i % 2 == j % 2) 
          ++ans;
    }
  cout << ans << '\n';
}

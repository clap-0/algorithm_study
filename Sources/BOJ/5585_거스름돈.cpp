#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int price;
  int money[6]={500, 100, 50, 10, 5, 1};
  cin >> price;
  int change = 1000-price, ans=0;
  for(int i=0; i<6; i++){
    ans += change/money[i];
    change %= money[i];
  }
  cout << ans << '\n';
}

#include <iostream>
#include <algorithm>
using namespace std;

int toppingCalories[100];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  int totalPrice, toppingPrice, totalCalories;
  cin >> N >> totalPrice >> toppingPrice >> totalCalories;
  for (int i = 0; i < N; i++)
    cin >> toppingCalories[i];
  
  sort(toppingCalories, toppingCalories + N, greater<int>());

  int ans = totalCalories / totalPrice;
  for (int i = 0; i < N; i++) {
    int tmp = (totalCalories += toppingCalories[i]) / (totalPrice += toppingPrice);
    if (tmp < ans) {
      break;
    }
    ans = tmp;
  }

  cout << ans << '\n';
}

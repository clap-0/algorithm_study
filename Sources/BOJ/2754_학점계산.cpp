#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  char score[3];
  cin >> score;
  if(score[0] == 'F')
    cout << "0.0" << '\n';
  else 
  {
    double ans = 4 - score[0] + 'A';
    switch(score[1])
    {
      case '+':
        ans += 0.3;
        break;
      case '-':
        ans -= 0.3;
        break;
      default:
        break;
    }
    cout << fixed;
    cout.precision(1);
    cout << ans << '\n';
  }
}

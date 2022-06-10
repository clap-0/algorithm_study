#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int height, weight;
    cin >> height >> weight;
    if(height <= 140) cout << 6 << '\n';
    else if(height < 146) cout << 5 << '\n';
    else if(height < 159) cout << 4 << '\n';
    else {
      double bmi = 1.0 * weight / ((height / 100.0)*(height / 100.0));
      if(height < 161) {
        if(16 <= bmi && bmi < 35) cout << 3 << '\n';
        else cout << 4 << '\n';
      }
      else if(height < 204) {
        if(20 <= bmi && bmi < 25) cout << 1 << '\n';
        else if(18.5 <= bmi && bmi < 30) cout << 2 << '\n';
        else if(16 <= bmi && bmi < 35) cout << 3 << '\n';
        else cout << 4 << '\n';
      }
      else cout << 4 << '\n';
    }
  }
}

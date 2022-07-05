#include <iostream>
#include <cmath>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, sum = 0;
  cin >> n;
  while(n)
  {
    sum += pow(n % 10, 5);
    n /= 10;
  }
  cout << sum << '\n';
}

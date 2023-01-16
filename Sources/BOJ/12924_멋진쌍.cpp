#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int A, B;
  cin >> A >> B;
  int ans = 0;
  // k = A와 자릿수가 같은 10의 제곱수
  int k = pow(10, floor(log10(A)));
  for (int x = A; x < B; x++) {
    int y = (x % 10) * k + (x / 10);
    // y와 x가 같은 경우, 이후의 반복문을 통해 나오는 y가 중복된다.
    // ex) 232323 -> 323232 -> 232323 -> 323232 -> ...
    while (y != x) {
      if (x < y && y <= B)
        ++ans;
      y = (y % 10) * k + (y / 10);
    }
  }
  
  cout << ans << '\n';
}

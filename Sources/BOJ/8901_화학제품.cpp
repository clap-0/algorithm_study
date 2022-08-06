#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--)
  {
    int A, B, C, AB, BC, CA;
    cin >> A >> B >> C >> AB >> BC >> CA;
    int ans = 0;
    // AB의 양을 정해두고, BC를 최대한 많이 만드는 것과 CA를 최대한 많이 만드는 것 중 이익이 더 큰 것을 구한다.
    for(int i = 0; i <= min(A, B); i++) // i : 만드는 AB의 양
    {
      int j = min(B - i, C);  // j : 만드는 BC의 양
      int k = min(A - i, C - j);  // k : 만드는 CA의 양
      ans = max(ans, AB*i + BC*j + CA*k);
      k = min(C, A - i);
      j = min(B - i, C - k);
      ans = max(ans, AB*i + BC*j + CA*k);
    }
    cout << ans << '\n';
  }
}

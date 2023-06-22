#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int S, K;
  cin >> S >> K;

  int Q = S / K, R = S % K;
  long long ans = 1;
  for (int i = 0; i < K; i++)
    ans *= (Q + (i < R));
  
  cout << ans << '\n';
}

#include <iostream>
#include <cmath>
using namespace std;

bool solve(long long k)
{
  if (k == 1)
    return 0;
  long long len = (long long)log2(k - 1);
  return !solve(k - (1LL << len));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  long long k;
  cin >> k;
  cout << solve(k) << '\n';
}

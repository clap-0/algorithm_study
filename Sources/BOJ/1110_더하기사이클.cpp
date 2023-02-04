#include <iostream>
using namespace std;

int solve(int n)
{
  int a = n / 10, b = n % 10;
  return b * 10 + (a + b) % 10;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  int ans = 1;
  int tmp = solve(N);
  while (tmp != N) {
    tmp = solve(tmp);
    ans++;
  }

  cout << ans << '\n';
}

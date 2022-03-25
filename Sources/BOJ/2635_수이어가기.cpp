#include <iostream>
using namespace std;

int solve(int a, bool b, int N) {
  int i = 0;
  while(N >= 0) {
    int tmp = N;
    if(b) cout << tmp << ' ';
    N = a;
    a = tmp - a;
    i++;
  }
  return i;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  int ans = -1, num = 0;
  for(int i = N / 2; i <= N; i++) {
    int tmp = solve(i, false, N);
    if(ans < tmp) {
      ans = tmp;
      num = i;
    }
  }

  cout << ans << '\n';
  solve(num, true, N);
}

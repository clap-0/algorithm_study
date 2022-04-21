#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, K;
  cin >> N >> K;

  // N의 켜져있는 비트의 개수가 K보다 크면
  // N의 가장 왼쪽의 켜져있는 비트 a와 그 다음으로 왼쪽에 있는 비트 b를 구하여
  // b - a를 더해 켜져있는 비트의 수를 줄인다
  int ans = 0;
  while(__builtin_popcount(N) > K) {
    int a = N & -N; N &= N - 1;
    int b = N & -N; N &= N - 1;
    ans += b - a;
    N += b << 1;
  }

  cout << ans << '\n';
}

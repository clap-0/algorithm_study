#include <iostream>
using namespace std;

const int MOD = 9901;

int cache[2][3];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  // cache[i][0] = 우리의 i번 행 왼쪽에 사자를 두는 경우
  // cache[i][1] = 우리의 i번 행 오른쪽에 사자를 두는 경우
  // cache[i][2] = 우리의 i번 행에 사자를 두지 않는 경우
  cache[0][0] = cache[0][1] = cache[0][2] = 1;
  for(int i = 1; i < N; i++) {
    cache[i % 2][0] = (cache[(i - 1) % 2][1] + cache[(i - 1) % 2][2]) % MOD;
    cache[i % 2][1] = (cache[(i - 1) % 2][0] + cache[(i - 1) % 2][2]) % MOD;
    cache[i % 2][2] = (cache[(i - 1) % 2][0] + cache[(i - 1) % 2][1] + cache[(i - 1) % 2][2]) % MOD;
  }

  cout << (cache[(N - 1) % 2][0] + cache[(N - 1) % 2][1] + cache[(N - 1) % 2][2]) % MOD << '\n';
}

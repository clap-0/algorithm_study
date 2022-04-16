#include <iostream>
using namespace std;

const int MAX_N = 1000000;

// psum[i] = g(i)
long long psum[MAX_N + 1];

// 에라토스테네스의 체 알고리즘을 응용하여 psum을 구한다
void init() {
  for(int i = 1; i <= MAX_N; i++) {
    for(int j = i; j <= MAX_N; j += i)
      psum[j] += i;
    psum[i] += psum[i - 1];
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T, N;
  cin >> T;
  init();
  while(T--) {
    cin >> N;
    cout << psum[N] << '\n';
  }
}

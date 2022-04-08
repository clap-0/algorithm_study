#include <iostream>
#include <cstring>
using namespace std;

int fail[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s;
  while(true) {
    cin >> s;
    if(s == ".") break;

    // KMP알고리즘의 실패함수
    int N = s.length();
    memset(fail, 0, sizeof(int) * N);
    for(int i = 1, j = 0; i < N; i++) {
      while(j > 0 && s[i] != s[j]) j = fail[j - 1];
      if(s[i] == s[j]) fail[i] = ++j;
    }

    // n > 1일 때, fail[N - 1] = ((n - 1) * N) / n 이 성립한다
    if(N % (N - fail[N - 1]) == 0) cout << N / (N - fail[N - 1]) << '\n';
    else cout << 1 << '\n';
  }
}

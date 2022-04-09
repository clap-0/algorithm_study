#include <iostream>
using namespace std;

// 실패함수
int fail[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string S, P;
  cin >> S >> P;

  int N = S.length(), M = P.length();
  // 실패함수 값을 구한다
  for(int i = 1, j = 0; i < M; i++) {
    while(j > 0 && P[i] != P[j]) j = fail[j - 1];
    if(P[i] == P[j]) fail[i] = ++j;
  }

  for(int i = 0, j = 0; i < N; i++) {
    // 현재 글자가 불일치하면 fail 값을 따라간다
    while(j > 0 && S[i] != P[j]) j = fail[j - 1];
    // 현재 글자가 일치하는 경우
    if(S[i] == P[j]) {
      // P가 S의 부분 문자열이면 1 출력 후 종료
      if(j == M - 1) {
        cout << 1 << '\n';
        return 0;
      }
      ++j;
    }
  }

  cout << 0 << '\n';
}

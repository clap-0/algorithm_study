#include <iostream>
using namespace std;

int fail[500000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string S;
  int K;
  cin >> S >> K;

  // S의 실패함수 구하기
  int N = S.length();
  for(int i = 1, j = 0; i < N; i++) {
    while(S[i] != S[j] && j > 0) j = fail[j - 1];
    if(S[i] == S[j]) fail[i] = ++j;
  }

  // 컴퓨터의 이름의 최소길이 = S를 K번 이어붙인 길이에 접두사와 일치하는 가장 긴 접미사의 길이(실패함수값)를 이어붙인 S 사이에서 뺀 값
  cout << 1LL * N * K - 1LL * fail[N - 1] * (K - 1);

  return 0;
}

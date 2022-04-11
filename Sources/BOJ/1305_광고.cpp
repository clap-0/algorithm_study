#include <iostream>
using namespace std;

// 실패함수. fail[i] : 문자열 S의 접두사 S[..i]에 대하여 S[..i]의 접두사와 일치하는 가장 긴 접미사의 길이
int fail[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int L;
  string str;
  cin >> L >> str;

  // str 문자열의 실패함수값을 구한다
  for(int i = 1, j = 0; i < L; i++) {
    while(j > 0 && str[i] != str[j]) j = fail[j - 1];
    if(str[i] == str[j]) fail[i] = ++j;
  }

  // 길이가 L인 문자열의 실패함수값 fail[L - 1]이 L/2보다 크다는 것은
  // 일치하는 접두사와 접미사가 겹친다는 뜻이므로
  // 길이가 fail[L - 1]인 접두사 내부에 가능한 가장 짧은 광고가 있다.
  while(fail[L - 1] > L / 2) L = fail[L - 1];

  // 전체 길이 L에서 중복되는 부분인(접두사, 접미사) 실패함수값을 빼면 가능한 가장 짧은 광고의 길이이다
  cout << L - fail[L - 1] << '\n';
}

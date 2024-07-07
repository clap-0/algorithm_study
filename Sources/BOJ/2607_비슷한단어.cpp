#include <iostream>
#include <cstring>
#define ALPHABET 26
using namespace std;

int ACnt[ALPHABET];  // ACnt: 문자열 A에서 알파벳의 구성
int BCnt[ALPHABET];  // BCnt: 문자열 B에서 알파벳의 구성

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int N;
  string A, B;
  
  cin >> N >> A;
  for (char ch : A) {
    ++ACnt[ch - 'A'];
  }

  int answer = 0;
  for (int i = 1; i < N; i++) {
    cin >> B;

    memset(BCnt, 0, sizeof(BCnt));
    for (char ch : B) {
      ++BCnt[ch - 'A'];
    }

    // 1. 한 문자를 더한 경우, 문자열 B가 특정 알파벳이 하나 더 많다.
    // 2. 한 문자를 뺀 경우, 문자열 A가 특정 알파벳이 하나 더 많다.
    // 3. 한 문자를 바꾼 경우, 문자열 A와 B 둘 다 서로 다른 알파벳이 하나씩 더 많다.
    // 따라서 A와 B의 구성이 서로 다른 부분의 개수(diff)를 계산하여 확인한다.
    int diff = 0;
    for (int j = 0; j < ALPHABET; j++) {
      diff += abs(ACnt[j] - BCnt[j]);
    }

    if (diff <= 1 || (diff == 2 && A.length() == B.length())) {
      ++answer;
    }
  }

  cout << answer << '\n';
}

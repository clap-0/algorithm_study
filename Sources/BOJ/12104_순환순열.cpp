#include <iostream>
using namespace std;

string A, B;
int fail[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> A >> B;

  int aLen = A.length(), bLen = aLen * 2 - 1;

  // 실패함수 구하기
  fail[0] = -1;
  for(int j = 1; j < aLen; j++) {
    int i = fail[j - 1];
    while(i >= 0 && A[j] != A[i + 1]) i = fail[i];
    if(A[j] == A[i + 1]) fail[j] = i + 1;
    else fail[j] = -1;
  }

  // KMP 알고리즘
  int ans = 0;
  int aPos = 0, bPos = 0;
  while(aPos < aLen && bPos < bLen) {
    if(A[aPos] == B[bPos % aLen]) {
      ++aPos;
      ++bPos;
      // 일치하는 경우 실패함수값을 이용하여 탐색을 이어나간다
      if(aPos == aLen) {
        ++ans;
        aPos = fail[aPos - 1] + 1;
      }
    }
    else {
      if(aPos == 0) ++bPos;
      else aPos = fail[aPos - 1] + 1;
    }
  }

  cout << ans << '\n';
}

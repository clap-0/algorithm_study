#include <iostream>
using namespace std;

int A[1000000];
int fail[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  // 앞부분을 잘라야 하므로 편의성을 위해 A를 역순으로 저장한다
  for(int i = N - 1; i >= 0; i--) cin >> A[i];

  // A의 실패함수를 구한다
  int coef = -1, cnt = 0;
  for(int i = 1, j = 0; i < N; i++) {
    while(A[i] != A[j] && j > 0) j = fail[j - 1];
    if(A[i] == A[j]) {
      fail[i] = ++j;
      // 앞뒤계수는 A 역순의 실패함수값의 최댓값이다
      if(fail[i] > coef) {
        coef = fail[i];
        cnt = 1;
      }
      else if(fail[i] == coef) ++cnt;
    }
  }

  if(cnt == 0) cout << -1 << '\n';
  else cout << coef << " " << cnt << '\n';

  return 0;
}

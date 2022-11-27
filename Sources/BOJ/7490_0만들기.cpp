#include <iostream>
using namespace std;

int N;
char ans[9];

void backtracking(int num, int cnt)
{
  if (cnt == N) {
    if (num == 0) {
      for (int i = 1; i < cnt; i++)
        cout << i << ans[i];
      cout << N << '\n';
    }
    return;
  }
  
  // 공백 삽입
  ans[cnt] = ' ';
  if (cnt > 1) {
    if (ans[cnt - 1] == '+')
      backtracking(num + cnt*10 + 1, cnt + 1);
    else if (ans[cnt - 1] == '-')
      backtracking(num - cnt*10 - 1, cnt + 1);
  }
  else  // cnt == 1인 경우
    backtracking(12, cnt + 1);

  // + 삽입
  ans[cnt] = '+';
  backtracking(num + cnt + 1, cnt + 1);
  // - 삽입
  ans[cnt] = '-';
  backtracking(num - cnt - 1, cnt + 1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    cin >> N;
    backtracking(1, 1);
    cout << '\n';
  }
}

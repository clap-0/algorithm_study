#include <iostream>
using namespace std;

const char P[3] = "OI";

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M, ans = 0;
  cin >> N >> M;

  bool flag = true;
  int count = 0;
  for(int i = 0; i < M; i++) {
    char ch;
    cin >> ch;
    if(ch == P[flag]) {
      if(ch == 'I') {
        if(count >= N) ++ans;
        ++count;
      }
      flag = !flag;
    }
    else {
      flag = (ch != 'I');
      count = (ch == 'I');
    }
  }
  cout << ans << '\n';
}

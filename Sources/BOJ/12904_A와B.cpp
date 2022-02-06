#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string S, T;
  cin >> S >> T;

  // S를 T로 만드는 방법이 아니라 T를 S로 만드는 방법이 있는지 찾는다
  int cnt = T.length() - S.length();
  while(cnt--) {
    char curr = T.back();
    T.pop_back();
    if(curr == 'B') reverse(T.begin(), T.end());
  }
  cout << (S == T) << '\n';
}

#include <iostream>
using namespace std;

int ans[10];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 1; i <= N; i++)
  {
    int left;
    cin >> left;

    // 배열의 값이 0인 왼쪽에서 left번째 칸에 i를 넣는다.
    int idx = -1;
    do {
      ++idx;
      while(ans[idx]) ++idx;
    } while(left--);
    ans[idx] = i;
  }

  for(int i = 0; i < N; i++)
    cout << ans[i] << ' ';
}

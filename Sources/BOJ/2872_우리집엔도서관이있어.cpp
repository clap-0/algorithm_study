#include <iostream>
using namespace std;

int books[300000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> books[i];

  // 정렬되지 않은 책만 움직이면 되므로,
  // 주어진 책들에서 마지막 수가 N인, 1씩 증가하는 부분 수열을 구한 후
  // 해당 수열의 책들을 제외한 나머지 책만 옮기면 된다.
  int ans = N;
  for (int i = N - 1; i >= 0; i--)
    if (books[i] == ans)
      --ans;
  
  cout << ans << '\n';
}

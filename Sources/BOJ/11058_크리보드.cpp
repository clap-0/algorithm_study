#include <iostream>
using namespace std;

long long cache[101]; // cache[i] = 버튼을 i번 눌러서 출력할 수 있는 A의 최대 개수

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  cache[1] = 1LL;
  for(int i = 2; i <= N; i++) {
    // 화면에 A 하나만 출력하는 경우
    cache[i] = cache[i - 1] + 1LL;
    // (j - 3)번째 때의 화면을 전체 선택, 복사해서 j번째 버튼부터 i번째까지 붙여넣기를 누르는 경우
    for(int j = i; j > 3; j--)
      cache[i] = max(cache[i], cache[j - 3] * (i - j + 2LL));
  }
  cout << cache[N] << '\n';
}

#include <iostream>
using namespace std;

int points[100];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> points[i];

  int ans = 0;
  for (int i = N - 2; i >= 0; i--) {
    if (points[i + 1] <= points[i]) {       // 특정 레벨의 점수가 그 다음 레벨의 점수와 같거나 더 많은 경우
      ans += points[i] - points[i + 1] + 1;
      points[i] = points[i + 1] - 1;        // 해당 레벨의 점수를 (다음 레벨의 점수 - 1)로 감소시킨다.
    }
  }
  cout << ans << '\n';
}

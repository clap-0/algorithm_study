#include <iostream>
#include <algorithm>
using namespace std;

int B[300000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  // 특정 드라이버의 순위를 높이는 가장 좋은 방법은 해당 드라이버가 N점을 받고,
  // 그 드라이버보다 점수가 높았던 나머지 드라이버들이
  // 점수가 높을수록 마지막 레이싱에서 더 낮은 점수를 받는 것이다.
  
  sort(B, B + N, greater<int>());

  // 점수가 가장 높았던 드라이버는 무조건 우승할 가능성이 있다.
  int ans = 1;
  
  // i번째 드라이버를 이길 가능성이 가장 높은 드라이버의 점수
  // 점수가 가장 높았던 드라이버가 1점을 받은 점수로 초기화한다.
  int score = B[0] + 1;

  for (int i = 1; i < N; i++) {
    if (score <= B[i] + N) {
      ++ans;
    }
    score = max(score, B[i] + i + 1);
  }

  cout << ans << '\n';
}

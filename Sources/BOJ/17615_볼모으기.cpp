#include <iostream>
#include <algorithm>  // reverse()
using namespace std;

// 볼을 오른쪽에서 왼쪽으로만 이동할 수 있을 때의 최소 이동 횟수를 구한다.
int minMoves(const string balls, int redCnt, int blueCnt) {
  // left: 맨 왼쪽에서부터 연속된 {빨간색, 파란색} 볼의 개수
  // left[0]과 left[1] 중 하나가 0이 아니면, 다른 하나는 0이다.
  int left[2] = {0, 0};

  // idx: 맨 왼쪽 볼의 색상이 빨간색이면 0, 파란색이면 1
  int idx = (balls[0] == 'R' ? 0 : 1);

  // 맨 왼쪽에서부터 연속된 같은 색상의 볼의 수를 구한다.
  ++left[idx];
  for (int i = 1; balls[i] == balls[0]; i++) {
    ++left[idx];
  }

  return min(redCnt - left[0], blueCnt - left[1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;
  string balls;
  cin >> N >> balls;

  // redCnt: 빨간색 볼의 개수, blueCnt: 파란색 볼의 개수
  int redCnt = 0, blueCnt = 0;
  for (char ball : balls) {
    if (ball == 'R') ++redCnt;
    else ++blueCnt;
  }

  // 오른쪽 → 왼쪽으로 볼을 움직이는 경우
  int ans = minMoves(balls, redCnt, blueCnt);

  // 왼쪽 → 오른쪽으로 볼을 움직이는 경우
  reverse(balls.begin(), balls.end());
  ans = min(ans, minMoves(balls, redCnt, blueCnt));

  cout << ans << '\n';
}

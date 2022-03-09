#include <iostream>
using namespace std;

int T, W;
bool plum[1000];
int dp[1000][31];

int solve(int time = 0, bool isLeft = true, int move = W) {
  // 모든 자두가 떨어진 경우
  if(time == T) return 0;
  
  // 메모이제이션
  int& ret = dp[time][move];
  if(ret) return ret;
  
  // 다른 나무로 움직이지 않는 경우
  ret = solve(time + 1, isLeft, move);
  
  // 현재 위치에 자두가 떨어지면 ret에 1을 더한다
  if(isLeft == plum[time]) ++ret;
  // 다른 위치에 떨어지면 움직였을 때와 안 움직였을 때 중 더 큰 값을 고른다
  else if(move) ret = max(ret, 1 + solve(time + 1, !isLeft, move - 1));
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> T >> W;
  for(int i = 0; i < T; i++) {
    int plumTree;
    cin >> plumTree;
    // 자두가 1번나무에 떨어지면 true, 2번에 떨어지면 false
    plum[i] = plumTree == 1;
  }

  cout << solve() << '\n';
}

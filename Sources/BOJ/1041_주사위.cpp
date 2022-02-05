#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  long long N;
  int dice[6];
  cin >> N;
  for(int i = 0; i < 6; i++) cin >> dice[i];

  long long ans = 0;
  
  // N이 1인 경우 ans는 가장 큰 수가 적힌 면을 제외한 5면의 수의 합이다
  if(N == 1) {
    int maxNum = 0;
    for(int i = 0; i < 6; i++) {
      ans += dice[i];
      maxNum = max(dice[i], maxNum);
    }
    ans -= maxNum;
  }
  // N이 2이상인 경우
  else {
    // 서로 마주보는 면의 수 중 더 작은 값들을 구한다
    int sides[3];
    for(int i = 0; i < 3; i++)
      sides[i] = min(dice[i], dice[5 - i]);
    
    sort(sides, sides + 3);
    int sum = 0;
    // 쌓아놓은 주사위 중 한 면만 보이는 경우 가장 작은 수가 보이도록 한다
    ans += (sum += sides[0]) * ((N - 2) * (N - 2) + 4 * (N - 2) * (N - 1));
    // 쌓아놓은 주사위 중 두 면이 보이는 경우 가장 작은 수와 두 번째로 작은 수가 보이도록 한다
    ans += (sum += sides[1]) * (4 * (N - 1) + 4 * (N - 2));
    // 쌓아놓은 주사위 중 세 면이 보이는 경우
    ans += (sum += sides[2]) * 4;
  }
  cout << ans << '\n';
}

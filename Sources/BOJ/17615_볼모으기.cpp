#include <iostream>
#include <algorithm>
using namespace std;

string balls;

// 일렬로 늘어진 볼에서 볼을 오른쪽으로 움직이는 것만 가능할 때
// 색깔별로 볼을 모으는 데 필요한 최소이동횟수를 구한다
int minMove(){
  int redMove=0, blueMove=0, redCnt=0, blueCnt=0;
    for(char ball : balls){
      if(ball == 'R'){
        redCnt++;
        blueMove += blueCnt;
        blueCnt = 0;
      }
      else {
        blueCnt++;
        redMove += redCnt;
        redCnt = 0;
      }
    }
  return min(redMove, blueMove);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N;
  cin >> N >> balls;

  int ans = minMove();
  // minMove()에서 볼을 왼쪽으로 이동시키는 경우도 확인하기 위해
  // balls 문자열을 뒤집는다
  reverse(balls.begin(), balls.end());
  cout << min(ans, minMove()) << '\n';
}

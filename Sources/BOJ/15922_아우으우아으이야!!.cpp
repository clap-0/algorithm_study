#include <iostream>
using namespace std;

const int MAX = 1e9;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  int ans = 0;
  int s, e;
  // s와 e를 x의 최솟값(-1,000,000,000)보다 작은 수로 초기화한다
  s = e = -(MAX+1);
  
  // 입력으로 주어지는 선분 [x,y]를 확인하며
  // 현재까지 만들어진 가장 오른쪽에 있는 선분 [s,e]와
  // 겹치는 경우 e를 y와 e중 최댓값으로 바꾸고
  // 겹치지 않는 경우 ans에 [s,e]의 길이를 더하고, 값을 [x,y]로 바꾼다
  for(int i=0; i<N; i++) {
    int x, y;
    cin >> x >> y;
    if(x <= e) e = max(e, y);
    else {
      ans += e - s;
      s = x, e = y;
    }
  }
  ans += e - s;
  cout << ans << '\n';
}

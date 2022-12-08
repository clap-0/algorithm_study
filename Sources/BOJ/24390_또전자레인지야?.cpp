#include <iostream>
#include <string>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string mmss;
  cin >> mmss;
  // 조리시간을 분과 초로 분리
  int mm = stoi(mmss.substr(0, 2));
  int ss = stoi(mmss.substr(3, 5));
  

  int ans = 1;  // 조리시작 버튼은 무조건 눌러야 하므로 1
  // 초단위가 30보다 작으면 10초를 여러번 누르고 조리시작을 누르고,
  // 30이상이면 조리시작을 누르고 10초를 여러번 누른다.
  ans += (ss < 30 ? ss : (ss - 30)) / 10;
  ans += mm / 10; // 10분 버튼
  ans += mm % 10; // 1분 버튼

  cout << ans << '\n';
}

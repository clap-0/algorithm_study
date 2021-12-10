#include <iostream>
using namespace std;

const int INF = 987654321;

// N개의 전구를 from에서 to로 바꾸기 위해 스위치를 눌러야 하는 횟수 반환. 불가능할 땐 INF 반환
int countSwitch(int N, string from, string to){
  int ret=0;
  for(int i=0; i<N-1; i++){
    // i번 전구가 from과 to에서 다른 경우 i+1번 스위치를 누른다
    if(from[i]!=to[i]){
      from[i] = from[i] == '0' ? '1' : '0';
      from[i+1] = from[i+1] == '0' ? '1' : '0';
      if(i+2<N) from[i+2] = from[i+2] == '0' ? '1' : '0';
      ++ret;
    }
  }
  return from == to ? ret : INF;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N;
  string from, to;
  cin >> N >> from >> to;
  int ans = countSwitch(N, from, to);
  // 1번 스위치를 누르고 나서 나머지 스위치를 눌러야 하는 횟수를 다시 구한다
  from[0] = from[0] == '0' ? '1' : '0';
  from[1] = from[1] == '0' ? '1' : '0';
  ans = min(ans, 1+countSwitch(N, from, to));
  cout << (ans<INF ? ans : -1) << '\n';
}

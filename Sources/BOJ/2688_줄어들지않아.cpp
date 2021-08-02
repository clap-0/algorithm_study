#include <iostream>
#include <cstring>
using namespace std;
long long cache[10][64];
//DP를 이용하여 다음 숫자가 nextNum인 줄어들지 않는 here자리의 수를 구한다
long long solve(int nextNum, int here){
  //기저사례 : 줄어들지 않는 수 하나를 완성한 경우 1 반환
  if(here==-1) return 1;
  //메모이제이션
  long long& ret = cache[nextNum][here];
  if(ret!=-1) return ret;
  ret=0;
  //현재 위치의 수보다 작거나 같은 수들로 줄어들지 않는 수를 만든다
  for(int currNum=0; currNum<=nextNum; currNum++) ret += solve(currNum, here-1);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  memset(cache, -1, sizeof(cache));
  while(T--){
    int n;
    cin >> n;
    cout << solve(9, n-1) << '\n';
  }
}

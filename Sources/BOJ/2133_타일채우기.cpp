#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N=15;
int n;
int cache[1<<MAX_N];
int tiling(int wall){
  if(wall == (1<<n)-1) return 1; //벽 다 채우면 1 반환
  int& ret=cache[wall];
  if(ret!=-1) return ret;
  ret=0;
  int notTiled = n - __builtin_popcount(wall); //아직 못 채운 벽 길이
  for(int i=1; i<=notTiled; i++)
    ret += tiling(((wall+1)<<i)-1)*(i!=1 ? 2 : 3); //3*2로 채우는 방법은 3가지 있고, 나머지는 2가지씩있음
  return ret;
}
int main()
{
  cin >> n;
  if(n%2) cout << 0 << endl; //n이 홀수면 벽을 채울 수 없다
  else{
    n/=2; //어차피 타일로 직사각형 만들면 무조건 가로가 2의배수이다
    memset(cache, -1, sizeof(cache));
    cout << tiling(0) << endl;
  }
  return 0;
}

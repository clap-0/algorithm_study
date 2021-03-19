#include <iostream>
#include <cstring>
using namespace std;
int cache[1001];
int MOD = 10007;
int tiling(int n)
{
  if(n==0) return 1; //기저사례:타일을 다 채웠을 때
  if(n<0) return 0; //기저사례:타일이 범위를 넘어섰을 때
  int& ret=cache[n];
  if(ret!=-1) return ret;
  return ret=(tiling(n-1)%MOD+2*tiling(n-2)%MOD)%MOD; //현위치에서 타일1x2로 채울때 경우의 수 + 2x1두 개나 2x2로 채울때 경우의 수
}
int main()
{
  int n;
  cin >> n;
  memset(cache, -1, sizeof(cache));
  cout << tiling(n) << endl;
  return 0;
}

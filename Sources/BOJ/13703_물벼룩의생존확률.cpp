#include <cstdio>
#include <cstring>
using namespace std;
//가능한 답의 최댓값이 (2^63)-1인 것 주의
long long cache[127][64];
//물벼룩이 현재 수면아래 below센티미터에 있을 때 sec초후 생존하는 경우의 수
long long survive(int below, int sec){
  //기저사례 : 현재 수면에 있는 경우 죽음
  if(below==0) return 0;
  //시간이 다 된 경우 생존
  if(sec==0) return 1;
  //메모이제이션
  long long& ret=cache[below][sec];
  if(ret!=-1) return ret;
  //1초 뒤에 위로 1cm 올라갔을 때 경우의 수 + 1cm 아래로 내려갔을 때 경우의 수
  return ret = survive(below-1,sec-1)+survive(below+1,sec-1);
}
int main()
{
  int k, n;
  scanf("%d %d", &k, &n);
  memset(cache, -1, sizeof(cache));
  printf("%lld\n", survive(k,n));
}

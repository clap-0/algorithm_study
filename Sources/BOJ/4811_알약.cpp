#include <cstdio>
#include <cstring>
using namespace std;
long long cache[31][31];
//알약 한 조각 전체의 개수 whole과 쪼갠 반 조각 개수 half가 주어질 때
//DP를 이용하여 가능한 경우의 수를 구한다
long long pills(int whole, int half){
  //메모이제이션
  long long& ret = cache[whole][half];
  if(ret!=-1) return ret;
  //알약 한 조각짜리가 하나도 없는 경우 남은 날은 무조건 반 조각씩만 먹는다
  if(whole==0) return ret=1;
  //알약 한 조각을 쪼개 반 조각은 넣는 경우
  ret=pills(whole-1, half+1);
  //알약 반 조각을 꺼내 먹는 경우
  if(half>0) ret+=pills(whole, half-1);
  return ret;
}
int main()
{
  int N;
  memset(cache, -1, sizeof(cache));
  while(1){
    scanf("%d", &N);
    if(N==0) break;
    printf("%lld\n", pills(N,0));
  }
}

#include <cstdio>
#include <cstring>
using namespace std;
int N;
int cache[1001][2][3];
//DP를 이용하여 지금까지의 출결횟수와 지각횟수, 연속결석횟수가 주어졌을 때
//개근상을 받을 수 있는 출결정보의 개수를 구한다
int nonAbsence(int today, int late, int absent){
  //기저사례 : 학기가 끝나면 1 반환
  if(today==N-1) return 1;
  //메모이제이션
  int& ret = cache[today+1][late][absent];
  if(ret!=-1) return ret;
  //내일 출석한 경우
  ret=nonAbsence(today+1, late, 0)%1000000;
  //지금까지 지각을 한번도 안 했을 때 내일 지각할 수 있다
  if(late==0) ret=(ret+nonAbsence(today+1, late+1, 0))%1000000;
  //연속으로 결석을 안 했거나 한번 한 경우 내일 결석할 수 있다
  if(absent<2) ret=(ret+nonAbsence(today+1, late, absent+1))%1000000;
  return ret;
}
int main()
{
  scanf("%d", &N);
  memset(cache, -1, sizeof(cache));
  printf("%d\n", nonAbsence(-1, 0, 0));
}

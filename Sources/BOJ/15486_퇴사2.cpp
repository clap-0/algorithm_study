#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int T[1500000], P[1500000], cache[1500000];
//Top-down방식 DP를 이용한 풀이
int maxProfit(int curr){
  //기저사례 : 오늘이 퇴사날이면 더 이상 일을 할 수 없다
  if(curr==N) return 0;
  //메모이제이션
  int& ret = cache[curr];
  if(ret!=-1) return ret;
  //오늘 일 안 하고 내일부터 일했을 때 버는 돈의 최댓값
  ret = maxProfit(curr+1);
  //오늘 일했을 때 퇴사 이후에 일이 끝나는 경우가 아니라면
  //오늘 일해서 버는 돈의 최댓값 구한다
  if(curr+T[curr]<=N) ret=max(ret, maxProfit(curr+T[curr])+P[curr]);
  return ret;
}
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d %d", &T[i], &P[i]);
  memset(cache, -1, sizeof(cache));
  printf("%d\n", maxProfit(0));
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int K[1000], S[1000];
int cache[100][10001];
//DP를 이용하여 time만큼의 시간이 남았을 때
//curr단원을 공부할 때와 안 할 때 중 최대 점수를 구한다
int maxScore(int curr, int time){
  //기저사례 : 모든 단원을 둘러본 경우 0반환
  if(curr==-1) return 0;
  //메모이제이션
  int& ret = cache[curr][time];
  if(ret!=-1) return ret;
  //curr단원을 버렸을 때 점수
  ret=maxScore(curr-1, time);
  //curr단원을 공부했을 때 점수와 비교한다
  if(time>=K[curr]) ret=max(ret, S[curr]+maxScore(curr-1, time-K[curr]));
  return ret;
}
int main()
{
  int N, T;
  scanf("%d %d", &N, &T);
  for(int i=0; i<N; i++) scanf("%d %d", K+i, S+i);
  memset(cache, -1, sizeof(cache));
  printf("%d\n", maxScore(N-1, T));
}

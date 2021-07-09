#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int W[101], V[101], cache[101][100001];
//Top-down방식의 DP를 이용하여 배낭문제 풀기
int packing(int item, int capacity){
  //모든 물건을 전부 확인했거나 더 이상 남은 용량이 없는 경우 0 반환
  if(item==0 || capacity==0) return 0;
  //메모이제이션
  int& ret = cache[item][capacity];
  if(ret!=-1) return ret;
  //이 물건은 넣지 않고 다음 물건을 확인한다
  ret = packing(item-1, capacity);
  //이 물건을 넣을 여유가 되는 경우 넣었을 때와 안 넣었을 때의 만족도 중 높은 것을 고른다
  if(capacity>=W[item]) ret=max(ret, packing(item-1, capacity-W[item]) + V[item]);
  return ret;
}
int main()
{
  int N, K;
  scanf("%d %d", &N, &K);
  for(int i=1; i<=N; i++) scanf("%d %d", &W[i], &V[i]);
  memset(cache, -1, sizeof(cache));
  printf("%d\n", packing(N, K));
}

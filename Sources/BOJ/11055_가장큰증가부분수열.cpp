#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int A[1000], cache[1000];
//curr번째 수에서 시작하는 가장 긴 증가부분수열의 합을 구한다
int lis(int curr){
  //메모이제이션
  int& ret = cache[curr];
  if(ret!=-1) return ret;
  //lis(curr) = curr 이후의 수에서 시작하는 lis의 합 + A[curr]이다
  ret=0;
  for(int next=curr+1; next<N; next++)
    if(A[curr]<A[next]) ret=max(ret, lis(next));
  return ret+=A[curr];
}
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &A[i]);
  memset(cache, -1, sizeof(cache));
  int ans=0;
  for(int start=0; start<N; start++)
    ans=max(ans, lis(start));
  printf("%d\n", ans);
}

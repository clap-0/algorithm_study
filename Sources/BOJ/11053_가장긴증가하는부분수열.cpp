#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int A[1000], cache[1001];
//DP를 이용하여 가장 긴 증가하는 부분수열 구하기
int lis(int start){
  //메모이제이션
  int& ret = cache[start+1];
  if(ret!=-1) return ret;
  ret=0;
  //start 이후의 수 중 A[start]보다 큰 수에서 재귀호출한다
  for(int next=start+1; next<N; next++)
    if(start==-1 || A[start]<A[next])
      ret = max(ret, lis(next)+1);
  return ret;
}
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &A[i]);
  memset(cache, -1, sizeof(cache));
  printf("%d\n", lis(-1));
}

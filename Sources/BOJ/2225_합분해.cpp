#include <cstdio>
#include <cstring>
using namespace std;
int cache[201][201];
int solve(int n, int k){
  //메모이제이션
  int& ret = cache[n][k];
  if(ret!=-1) return ret;
  //더 이상 더 할 정수가 없을 때 답을 구한 경우 1, 아니면 0 반환
  if(k==0) return ret = n==0;
  ret=0;
  for(int i=0; i<=n; i++) ret=(ret+solve(n-i,k-1))%1000000000;
  return ret;
}
int main()
{
  int N, K;
  scanf("%d %d", &N, &K);
  memset(cache, -1, sizeof(cache));
  printf("%d\n", solve(N,K));
}

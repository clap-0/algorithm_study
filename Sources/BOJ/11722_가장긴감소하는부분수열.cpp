#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int A[1000], cache[1001];
//DP를 이용하여 A_start에서 시작하는 가장 긴 감소하는 부분수열 구하기
int lds(int start=-1){
  //메모이제이션
  int& ret = cache[start+1];
  if(ret!=-1) return ret;
  //LDS의 최소길이==1
  ret=1;
  //A_start보다 작은 start이후의 수에서 재귀호출한다
  for(int next=start+1; next<N; next++)
    if(start==-1 || A[start]>A[next]) ret=max(ret, lds(next)+1);
  return ret;
}
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &A[i]);
  memset(cache, -1, sizeof(cache));
  printf("%d\n", lds()-1);
}

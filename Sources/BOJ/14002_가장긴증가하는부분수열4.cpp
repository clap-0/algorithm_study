#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
//nextNum[i] = LIS에서 A_i 다음에 오는 수. i가 마지막 수면 -1
int A[1001], nextNum[1001], cache[1001];
//DP를 이용하여 A_start에서 시작하는 가장 긴 증가하는 부분수열의 길이와
//가장 긴 증가하는 부분수열에서 A_start 다음에 오는 수 구하기
int lis(int start=0){
  //메모이제이션
  int& ret = cache[start];
  if(ret!=-1) return ret;
  //수열의 최소길이==1
  //A_start이후에 A_start보다 큰 수가 없으면 nextNum[start]==-1
  ret=1, nextNum[start]=-1;
  //A_start보다 큰 수에서 재귀호출하여 그 수에서 시작하는 LIS의 길이를 구함
  for(int next=start+1; next<=N; next++)
    if(start==0||A[start]<A[next]){
      int length = lis(next);
      if(ret < length+1){
        ret = length+1;
        nextNum[start] = next;
      }
    }
  return ret;
}
int main()
{
  scanf("%d", &N);
  for(int i=1; i<=N; i++) scanf("%d", &A[i]);
  memset(cache, -1, sizeof(cache));
  int length = lis()-1;
  printf("%d\n", length);
  for(int t=nextNum[0]; t!=-1; t=nextNum[t]) printf("%d ", A[t]);
}

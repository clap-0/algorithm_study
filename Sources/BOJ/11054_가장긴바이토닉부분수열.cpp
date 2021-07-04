#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int A[1000], cache[1000][2];
//DP를 이용해 시작위치와 증가 혹은 감소 중인지를 인자로 받아
//가장 긴 바이토닉 부분 수열의 길이를 구한다
int lbs(int start, bool isUp){
  //메모이제이션
  int& ret = cache[start][isUp];
  if(ret!=-1) return ret;
  ret=1;
  for(int next=start+1; next<N; next++){
    if(A[start]>A[next]) ret=max(ret, lbs(next, false)+1);
    //증가 중일 때만 증가하는 바이토닉 부분 수열을 구할 수 있다
    else if(isUp && A[start]<A[next]) ret=max(ret, lbs(next, true)+1); 
  }
  return ret;
}
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &A[i]);
  memset(cache, -1, sizeof(cache));
  int length=1;
  for(int i=0; i<N; i++) length=max(length, lbs(i, true));
  printf("%d\n", length);
}

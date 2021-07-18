#include <cstdio>
#include <cstring>
using namespace std;
int N;
int num[100];
long long cache[100][21];
//현재 확인 중인 숫자의 위치 pos와 지금까지 계산한 값 value가 주어졌을 때
//DP를 이용하여 만들 수 있는 올바른 등식의 수 반환
long long solve(int pos, int value){
  //기저사례 : 등식을 만들었을 때 이 등식이 올바르면 1, 틀리면 0 반환
  if(pos+1==N) return value==num[pos];
  //메모이제이션
  long long& ret = cache[pos][value];
  if(ret!=-1) return ret;
  ret=0;
  //계산한 중간 값이 0이상 20이하가 되도록 현 위치의 수를 더하거나 뺀다 
  if(value-num[pos]>=0) ret += solve(pos+1, value-num[pos]);
  if(value+num[pos]<=20) ret += solve(pos+1, value+num[pos]);
  return ret;
}
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d", &num[i]);
  memset(cache, -1, sizeof(cache));
  printf("%lld\n", solve(1, num[0]));
}

#include <cstdio>
#include <cstring>
using namespace std;
long long cache[91][2];
//DP를 이용하여 num으로 끝나는 n자리 이친수의 개수를 구한다
long long countPinary(int n, bool num){
  //기저사례1 : n이 0 또는 음수이면 범위 밖이므로 0 반환
  if(n<1) return 0;
  //기저사례2 : n이 1이면 가능한 이친수가 1밖에 없으므로 1 반환
  if(n==1) return num;
  //메모이제이션
  long long& ret = cache[n][num];
  if(ret!=-1) return ret;
  return ret = countPinary(n-1, 0) + (num ? 0 : countPinary(n-1, 1));
}
int main()
{
  int N;
  scanf("%d", &N);
  memset(cache, -1, sizeof(cache));
  printf("%lld\n", countPinary(N, 1)+countPinary(N, 0));
}

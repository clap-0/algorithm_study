#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF=987654321;
int n, k;
int coins[100], cache[10001];
//DP를 이용하여 remaining을 0으로 만드는데 필요한 동전의 개수 구한다
int solve(int remaining){
  //기저사례1 : remaining이 음수면 불가능
  if(remaining<0) return INF;
  //기저사례2 : remaining을 0으로 만들었으면 0 반환
  if(remaining==0) return 0;
  //메모이제이션
  int& ret = cache[remaining];
  if(ret!=-1) return ret;
  ret = INF;
  //remaining에서 필요한 동전 개수의 최솟값 구하기
  for(int i=0; i<n; i++)
    ret = min(ret, solve(remaining-coins[i]));
  return ++ret;
}
int main()
{
  scanf("%d %d", &n, &k);
  for(int i=0; i<n; i++) scanf("%d", &coins[i]);
  memset(cache, -1, sizeof(cache));
  int ans = solve(k);
  printf("%d\n", ans<INF ? ans : -1);
}

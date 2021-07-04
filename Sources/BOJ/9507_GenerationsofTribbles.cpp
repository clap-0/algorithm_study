#include <cstdio>
#include <cstring>
long long dp[68];
using namespace std;
//Top-down 방식을 이용한 DP풀이
long long koong(int n){
  long long& ret = dp[n];
  if(ret!=-1) return ret;
  return ret = koong(n-1)+koong(n-2)+koong(n-3)+koong(n-4);
}
int main()
{
  int t;
  memset(dp, -1, sizeof(dp));
  dp[0]=dp[1]=1, dp[2]=2, dp[3]=4;
  scanf("%d", &t);
  while(t--){
    int n;
    scanf("%d", &n);
    printf("%lld\n", koong(n));
  }
}

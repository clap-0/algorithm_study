#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
  int T;
  int dp[1000001]={0};
  scanf("%d", &T);
  //Bottom-up방식을 이용한 DP
  dp[1]=1, dp[2]=2, dp[3]=4;
  for(int i=4; i<=1000000; i++)
    for(int j=1; j<=3; j++)
      dp[i] = (dp[i]+dp[i-j])%1000000009;
  while(T--){
    int n;
    scanf("%d", &n);
    printf("%d\n", dp[n]);
  }
}

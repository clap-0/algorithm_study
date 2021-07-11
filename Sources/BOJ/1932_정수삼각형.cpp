#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  int dp[501][501]={0};
  scanf("%d %d", &n, &dp[1][1]);
  //Bottom-up 방식의 DP
  for(int i=2; i<=n; i++)
    for(int j=1; j<=i; j++){
      scanf("%d", &dp[i][j]);
      dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
    }
  printf("%d\n", *max_element(dp[n], dp[n]+n+1));
}

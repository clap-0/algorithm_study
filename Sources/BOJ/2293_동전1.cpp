#include <cstdio>
using namespace std;
int main()
{
  int n, k;
  int coin[100];
  int dp[2][10001]={0};
  scanf("%d %d", &n, &k);
  for(int i=0; i<n; i++) scanf("%d", &coin[i]);
  //슬라이딩-윈도우를 활용한 반복
  dp[0][0]=dp[1][0]=1;
  for(int i=0; i<n; i++)
    for(int j=1; j<=k; j++){
      dp[i%2][j]=dp[(i+1)%2][j];
      if(j>=coin[i]) dp[i%2][j]+=dp[i%2][j-coin[i]];
    }
  printf("%d\n", dp[(n-1)%2][k]);
}

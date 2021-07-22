#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
  int N;
  int P[1001], dp[1001];
  scanf("%d", &N);
  for(int i=1; i<=N; i++) scanf("%d", P+i);
  //반복적동적계획법
  dp[1]=P[1];
  for(int i=2; i<=N; i++){
    dp[i]=P[i];
    for(int j=1; j<=i; j++)
      dp[i]=min(dp[i], P[j]+dp[i-j]);
  }
  printf("%d\n", dp[N]);
}

#include <cstdio>
using namespace std;
int main()
{
  int N;
  //dp[i] = 돌이 i개 남았을 때 지금 차례인 사람이 이길 수 있는가
  bool dp[1001];
  scanf("%d", &N);
  //마지막 돌을 가져간 사람이 지게된다
  dp[1]=dp[3]=false, dp[2]=dp[4]=true;
  //지금 차례인 사람이 돌을 가져간 이후에
  //다음 사람이 무조건 지게 되는 경우가 하나라도 있으면 이길 수 있다
  for(int i=5; i<=N; i++)
    dp[i]=!(dp[i-1]&&dp[i-3]&&dp[i-4]);
  printf("%s\n",dp[N]?"SK":"CY");
}

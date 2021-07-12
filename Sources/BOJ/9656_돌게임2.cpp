#include <cstdio>
using namespace std;
int main()
{
  int N;
  //dp[i] = 돌이 i개 있을 때 해당 차례인 사람의 승리여부
  bool dp[1001];
  scanf("%d", &N);
  //Bottom-up 방식의 DP
  dp[1]=dp[3]=0, dp[2]=1;
  for(int i=4; i<=N; i++)
    dp[i]=!(dp[i-1]||dp[i-3]);
  printf("%s\n", dp[N]?"SK":"CY");
  //사실 DP를 쓰지 않아도 N이 짝수면 상근이가, 홀수면 창영이가 이기는 걸 알 수 있다
}

#include <cstdio>
using namespace std;
int main()
{
  // 1과 5로만 구성된 15의 배수를 구해야 하므로
  // 구하는 수는 일의 자리가 5인 3의 배수가 된다.(일의 자리가 5면 5의 배수이므로)
  //dp[i][j] = i자리 수 중 3으로 나눈 나머지가 j인 수의 개수
  int N, dp[1516][3]={0};
  scanf("%d", &N);
  //15, 55
  dp[2][0] = dp[2][1] = 1;
  //모듈러 덧셈의 속성과
  //(1*10^k)%3 == 1, (5*10^k)%3 == 2 (k는 자연수) 임을 이용한다
  for(int i=3; i<=N; i++)
    for(int r=0; r<3; r++)
      dp[i][r] = (dp[i-1][(r+1)%3] + dp[i-1][(r+2)%3]) % 1000000007;
  printf("%d\n", dp[N][0]);
}

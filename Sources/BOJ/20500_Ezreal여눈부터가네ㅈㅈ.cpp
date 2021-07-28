#include <cstdio>
using namespace std;
int main()
{
  //dp[i][j] = i자리 수 중 15로 나눈 나머지가 j인 수의 개수
  int N, dp[1516][15]={0};
  scanf("%d", &N);
  //반복적 동적계획법
  dp[1][1] = dp[1][5] = 1;
  for(int i=2; i<=N; i++)
    for(int remainder=0; remainder<15; remainder++)
      //모듈러 연산의 속성을 이용한다
      if(dp[i-1][remainder]){
        dp[i][(10+remainder)%15] = (dp[i][(10+remainder)%15] + dp[i-1][remainder])%1000000007;
        dp[i][(50+remainder)%15] = (dp[i][(50+remainder)%15] + dp[i-1][remainder])%1000000007;
      }
  printf("%d\n", dp[N][0]);
}

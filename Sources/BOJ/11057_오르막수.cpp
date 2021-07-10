#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
  int N, ascent=0;
  //dp[i][j] = 길이가 i인 j로 끝나는 오르막수의 개수
  int dp[1001][10]={0};
  scanf("%d", &N);
  //Bottom-up 방식의 DP를 이용해 오르막수 구하기
  for(int i=1; i<=N; i++){
    //0으로 끝나는 오르막수는 00...0 1개뿐이다
    dp[i][0]=1;
    //마지막 수가 j인 길이 i의 오르막 수의 개수는
    //마지막 수가 j보다 작거나 같은 길이 i-1의 오르막 수의 개수의 합이다
    //이때 길이 i-1의 마지막 수가 j보다 작은 오르막 수의 개수는
    //직전에 구한 마지막 수가 j-1인 길이 i의 오르막 수의 개수와 같다
    for(int j=1; j<10; j++)
      dp[i][j] = (dp[i-1][j]+dp[i][j-1])%10007;
  }
  for(int i=0; i<10; i++) ascent+=dp[N][i];
  printf("%d\n", ascent%10007);
}

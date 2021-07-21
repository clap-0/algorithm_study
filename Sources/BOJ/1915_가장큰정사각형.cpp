#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
  int n, m, biggest=0;
  int dp[2][1001]={0};
  scanf("%d %d", &n, &m);
  //반복적동적계획법을 이용하여 문제풀기
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++){
      char ch;
      scanf(" %c", &ch);
      //배열의 수가 1이면 현위치의 왼쪽위에 있는 정사각형의 변의 길이를 구한다
      if(ch=='0') dp[i%2][j]=0;
      else{
        dp[i%2][j] = 1 + min(dp[i%2][j-1], min(dp[(i-1)%2][j-1], dp[(i-1)%2][j]));
        biggest=max(biggest, dp[i%2][j]);
      }
    }
  printf("%d\n", biggest*biggest);
}

#include <cstdio>
using namespace std;
int dp[3001][3001]={0};
char map[3000][3000];
int main()
{
  int N, M, path=0;
  scanf("%d %d", &N, &M);
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      scanf(" %c", &map[i][j]);
  //반복적동적계획법으로 풀기
  dp[N-1][M-1]=1;
  for(int i=N-1; i>=0; i--)
    for(int j=M-1; j>=0; j--){
      switch(map[i][j]){
        case 'E':dp[i][j]=dp[i][j+1]; break;
        case 'S':dp[i][j]=dp[i+1][j]; break;
        case 'B':dp[i][j]=(dp[i+1][j]+dp[i][j+1])%1000000009; break;
      }
      path = (path+dp[i][j])%1000000009;
    }
  printf("%d\n", path);
}

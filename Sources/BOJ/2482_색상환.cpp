#include <iostream>
using namespace std;

// dp[N][K] = N개의 색나열 [1,N]중에 N과 인접하지 않은 K개를 뽑는 경우의 수
int dp[1001][501];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, K;
  cin >> N >> K;
  
  // N색상환에서 선택된 수가 서로 인접하지 않게 뽑는 최대 개수는 N/2개이다
  if(N<K*2){
    cout << 0 << '\n';
    return 0;
  }
  
  // 반복적 동적계획법
  // N색상환이 아닌 N개의 일렬로 나열된 색으로 생각하고 문제를 푼 후 이를 이용해 원래 문제를 푼다
  for(int i=0; i<=N; i++) dp[i][0]=1;
  dp[1][1]=1;
  // 색나열 [1,n]에서 n과 인접하지 않은 k개를 선택할 때
  // 1. n을 선택하는 경우: 다음으로 선택하는 수는 n과 인접하면 안 되므로 dp[n-2][k-1]
  // 2. n을 선택하지 않는 경우: 다음 선택하는 수는 n과 상관없으므로 dp[n-1][k]
  for(int n=2; n<=N; n++)
    for(int k=1; k<=min(n,K); k++)
      dp[n][k]=(dp[n-2][k-1]+dp[n-1][k])%1000000003;
  
  // N색상환은 고리모양이므로
  // N번째 색을 선택한 경우: N-1번째 색과 1번째 색을 선택하지 못하므로 dp[N-3][K-1]
  int ans=(dp[N-3][K-1]+dp[N-1][K])%1000000003;
  cout << ans << '\n';
}

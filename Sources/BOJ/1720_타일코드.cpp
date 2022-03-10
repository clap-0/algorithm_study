#include <iostream>
using namespace std;

int dp[31];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  // dp[i] = 크기가 i인 타일의 좌우대칭을 고려하지 않은 타일 코드의 개수
  dp[0] = 1, dp[1] = 1;
  for(int i = 2; i <= N; i++) 
    dp[i] = dp[i - 1] + 2 * dp[i - 2];
  
  // symmetric = 타일코드 중 중앙을 기준으로 좌우가 대칭인 코드의 개수
  int symmetric = (N % 2 == 1 ? dp[N / 2] : dp[N / 2] + 2 * dp[N / 2 - 1]);
  
  // symmetric만큼의 타일코드를 제외한 다른 코드들은 서로 한 쌍씩 좌우대칭을 이룬다
  cout << symmetric + (dp[N] - symmetric) / 2 << '\n';
}

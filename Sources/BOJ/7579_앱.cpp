#include <cstdio>
#include <algorithm>
using namespace std;

int m[100], c[100];
// dp[i] = i만큼의 비용으로 확보할 수 있는 메모리의 최댓값
int dp[10001];

int main()
{
  int N, M;
  int costSum = 0;
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) scanf("%d", m + i);
  for(int i = 0; i < N; i++) {
    scanf("%d", c + i);
    costSum += c[i];
  }

  // j만큼의 비용으로 확보할 수 있는 메모리의 양은
  // (i번째 앱을 활성화시키는 경우, i번째 앱을 비활성화시키는 경우) 중 최댓값이다
  for(int i = 0; i < N; i++) 
    // 중복을 제외하기 위해 costSum에서 감소시키는 순서로 구한다
    for(int j = costSum; j >= c[i]; j--) 
      dp[j] = max(dp[j], dp[j - c[i]] + m[i]);

  // M이상의 메모리를 확보할 수 있는 비용의 최솟값을 구한다
  int ans = lower_bound(dp, dp + costSum, M) - dp;
  printf("%d\n", ans);
}

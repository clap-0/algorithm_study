#include <cstdio>
#include <algorithm>
using namespace std;

double arr[10000];
double dp[10000];

int main() 
{
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%lf", arr + i);

  // dp[i] = [0, i]범위에서 i번째 수를 포함하는 연속부분최대곱의 값
  dp[0] = arr[0];
  double ans = 0.0;
  for(int i = 1; i < N; i++) {
    dp[i] = arr[i] * (dp[i - 1] < 1.0 ? 1.0 : dp[i - 1]);
    ans = max(ans, dp[i]);
  }
  printf("%.3lf\n", ans);
}

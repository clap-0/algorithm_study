#include <iostream>
#include <cstring>
using namespace std;

int N;
int A[2000], B[2000];
int dp[2000][2000];

int solve(int a, int b) {
  // 왼쪽 혹은 오른쪽 더미에 더 이상 남은 카드가 없는 경우 0 반환
  if(a >= N || b >= N) return 0;
  
  // 메모이제이션
  int& ret = dp[a][b];
  if(ret != -1) return ret;
  
  // 규칙(2)
  if(A[a] > B[b]) ret = B[b] + solve(a, b + 1);
  // 규칙(1). 규칙상으로는 언제든지 할 수 있다고 명시되어있지만
  // 오른쪽카드에 적힌 수가 왼쪽보다 작으면 규칙(2)에 따라 무조건 오른쪽을 버리는게 이득이다
  else ret = max(solve(a + 1, b), solve(a + 1, b + 1));
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];

  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0) << '\n';
}

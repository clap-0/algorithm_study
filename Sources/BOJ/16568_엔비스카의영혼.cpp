#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, a, b;
  cin >> N >> a >> b;

  // dp[i] = 앞에 i명의 사람이 있을 때 줄의 맨 앞에 서기까지 걸리는 최소시간
  fill(dp, dp+N+1, 987654321);
  dp[0] = 0;
  for(int i=0; i<N; i++) {
    // 기다리는 경우
    dp[i+1] = min(dp[i+1], dp[i]+1);
    // 맨 앞 한 명이 가고 a명 혹은 b명을 새치기하는 경우
    if(i+a+1<=N) dp[i+a+1] = min(dp[i+a+1], dp[i]+1);
    if(i+b+1<=N) dp[i+b+1] = min(dp[i+b+1], dp[i]+1);
  }
  cout << dp[N] << '\n';
}

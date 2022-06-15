#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int C, N;
  cin >> C >> N;

  vector<int> dp(C + 1, INF);
  dp[0] = 0;
  // Knapsack Problem
  for(int i = 0; i < N; i++) {
    int cost, people;
    cin >> cost >> people;
    // 여러 번 중복된 도시에 돈을 쓸 수 있게 k를 0부터 정순으로 시작
    for(int k = 0; k < C; k++)
      if(dp[k] < INF) // 호텔 고객을 C명 이상 늘이는 경우를 구하므로 min(C, k + people) 사용
        dp[min(C, k + people)] = min(dp[min(C, k + people)], cost + dp[k]);
  }

  cout << dp[C] << '\n';
}

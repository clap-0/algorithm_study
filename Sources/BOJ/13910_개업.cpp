#include <iostream>
#include <set>
using namespace std;

int woks[100];
int dp[10001];
set<int> atOnce;  // 한 번의 요리로 완성할 수 있는 짜장면 그릇 수

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;

  // 웍 하나로 한 번에 모든 주문을 처리할 수 있는 경우
  for (int i = 0; i < M; i++) {
    cin >> woks[i];
    atOnce.insert(woks[i]);
  }
  // 웍 두 개로 한 번에 모든 주문을 처리할 수 있는 경우
  for (int i = 0; i < M; i++)
    for (int j = i + 1; j < M; j++) 
      atOnce.insert(woks[i] + woks[j]);

  // dp를 INF로 초기화
  for (int i = 1; i <= N; i++)
    dp[i] = 987654321;
  dp[0] = 0;

  // Dynamic Programming
  for (auto it = atOnce.begin(); it != atOnce.end(); it++) {
    int num = *it;
    // atOnce가 정렬되어 있으므로 num > N 이면 이후의 원소들은 탐색할 필요가 없다. 
    if (num > N)
      break;
    for (int k = num; k <= N; k++)
      dp[k] = min(dp[k], 1 + dp[k - num]);
  }

  cout << (dp[N] != 987654321 ? dp[N] : -1) << '\n';
}

#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[1000001];

int solution(vector<int> money) {
    int answer = 0;
    int N = money.size();

    // 집들이 원형으로 배치되어 있으므로 1번 집을 털면 N번 집을 털지 못한다
    // 따라서 1번 집을 터는 경우와 털지 않는 경우를 나누어서 계산한다
  
    // 1번 집을 털지 않는 경우 2번 집에서 N번 집 사이에서 훔칠 수 있는 돈의 최댓값을 구한다
    for(int i = 2; i <= N; i++) {
        dp[i] = max(dp[i - 1], dp[max(0, i - 2)] + money[i - 1]);
    }
    answer = dp[N];

    // 1번 집을 터는 경우 3번 집에서 N-1번 집 사이에서 훔칠 수 있는 돈의 최댓값을 구한다
    memset(dp, 0, sizeof(dp));
    for(int i = 3; i < N; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i - 1]);
    }
    answer = max(answer, dp[N - 1] + money[0]);

    return answer;
}

#include <iostream>
#include <cstring>
using namespace std;

// scores[i][j] = i번 팀의 j번 문제에 대한 최고 점수
// scores[i][0] = i번 팀의 최종 점수(각 문제에 대한 점수의 총합)
int scores[101][101];

// submitCnt[i] = i번 팀의 풀이 제출 횟수
int submitCnt[101];

// lastSubmitTime[i] = i번 팀의 마지막 제출 시간
int lastSubmitTime[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int T;
  cin >> T;
  
  while (T--) {
    // n: 팀의 개수    k: 문제의 개수
    // t: 우리 팀 ID  m: 로그 엔트리의 개수
    int n, k, t, m;
    cin >> n >> k >> t >> m;

    // 배열의 원소를 0으로 초기화
    memset(scores, 0, sizeof(scores));
    memset(submitCnt, 0, sizeof(submitCnt));
    memset(lastSubmitTime, 0, sizeof(lastSubmitTime));
    
    for (int time = 0; time < m; time++) {
      // i: 팀 ID    j: 문제번호    s: 획득한 점수
      int i, j, s;
      cin >> i >> j >> s;

      ++submitCnt[i];
      lastSubmitTime[i] = time;
      // j번 문제를 과거보다 더 높은 점수를 받은 경우, 최고점수와 최종점수 최신화
      if (scores[i][j] < s) {
        scores[i][0] += s - scores[i][j];
        scores[i][j] = s;
      }
    }

    int rank = 1;
    for (int team = 1; team <= n; team++) {

      // 1. 최종 점수가 우리 팀보다 높은 경우
      // 2. 최종 점수가 같고, 풀이를 제출한 횟수가 우리 팀보다 적은 경우
      // 3. 최종 점수와 제출 횟수가 같고, 마지막 제출 시간이 우리 팀보다 빠른 경우
      if (scores[team][0] > scores[t][0] || 
          (scores[team][0] == scores[t][0] && (submitCnt[team] < submitCnt[t] ||
          (submitCnt[team] == submitCnt[t] && lastSubmitTime[team] < lastSubmitTime[t])))) {
          // 우리 팀의 순위를 낮춤
          ++rank;
      }
    }

    cout << rank << '\n';
  }
}

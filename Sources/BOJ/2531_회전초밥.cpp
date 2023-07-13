#include <iostream>
using namespace std;

int sushiOnBelt[30000];  // 회전 초밥 벨트의 각 접시에 놓인 초밥의 종류
int eatableSushi[3001];  // 각 종류의 초밥에 대해 먹을 수 있는 갯수

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, d, k, c;
  cin >> N >> d >> k >> c;
  for (int i = 0; i < N; i++)
    cin >> sushiOnBelt[i];

  int ans = 0;  // 먹을 수 있는 초밥의 가짓수의 최댓값
  int foodVariety = 0; // 먹을 수 있는 초밥의 가짓수

  // 뒤에서 최대 k개의 초밥을 먹을 때, 먹을 수 있는 초밥의 가짓수를 구한다.
  for (int i = max(0, N - k); i < N; i++) {
    if (++eatableSushi[sushiOnBelt[i]] == 1) {
      ++foodVariety;
    }
  }
  ans = foodVariety + (eatableSushi[c] == 0);

  if (k < N) {
    // 0 번부터 N-1 번 위치까지, 각각의 위치에서 연속된 k 개의 초밥을 먹을 때
    // 먹을 수 있는 초밥의 가짓수를 구한다.
    int lo = N - k, hi = 0;
    while (hi < N) {  // 계산의 편의를 위해 hi를 [0, N-1] 범위로 증가시키며 hi를 기준으로 계산했다.
      if (--eatableSushi[sushiOnBelt[lo]] == 0) {
        --foodVariety;
      }
      lo = (lo + 1) % N;

      if (++eatableSushi[sushiOnBelt[hi++]] == 1) {
        ++foodVariety;
      }

      ans = max(ans, foodVariety + (eatableSushi[c] == 0));
    }
  }

  cout << ans << '\n';
}

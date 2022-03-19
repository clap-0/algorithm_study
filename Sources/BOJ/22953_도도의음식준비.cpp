#include <iostream>
using namespace std;

int N, K, C;
int A[10];
long long ans = 1e12;

// 파라메트릭서치를 통해
// 요리사들의 음식 조리 시간 A를 이용하여
// K개의 요리를 하는데 필요한 최소시간을 구한다
void parametricSearch() {
  long long lo = 1, hi = 1e12;
  while(lo <= hi) {
    long long mid = (lo + hi) / 2;
    long long sum = 0;
    for(int i = 0; i < N; i++) sum += mid / A[i];
    if(sum < K) lo = mid + 1;
    else {
      hi = mid - 1;
      ans = min(ans, mid);
    }
  }
}

// 백트래킹을 통해 도도가 요리사들을 격려하는 모든 경우를 찾는다
void backtracking(int pos = 0, int cnt = 0) {
  // C번 격려한 경우, 음식조리시간을 구한다
  if(cnt == C) {
    parametricSearch();
    return;
  }
  // 중복을 제거하기 위해 마지막으로 격려한 사람(pos)부터 시작한다
  for(int i = pos; i < N; i++)
    if(A[i] > 1) {
      --A[i];
      backtracking(i, cnt + 1);
      ++A[i];
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> K >> C;
  int sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
  }

  if(sum - C > N) backtracking();
  // C번이하로 격려한 후에 모든 요리사들의 조리시간이 1인 경우
  // K개의 요리를 조리하는데 걸리는 시간을 바로 구한다
  else ans = (K + N - 1) / N;
  cout << ans << '\n';
}

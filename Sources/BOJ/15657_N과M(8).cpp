#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int numbers[8];
int sequence[8];

// 백트래킹을 이용하여 조건을 만족하는 수열들을 출력하는 함수
void backtracking(int idx, int cnt) {
  // 길이가 M인 수열을 완성한 경우, 수열 출력 후 종료
  if(cnt == M) {
    for(int i = 0; i < M; i++) cout << sequence[i] << ' ';
    cout << '\n';
    return;
  }

  // 비내림차가 되도록 수열의 cnt번째 수를 선택한다
  for(int i = idx; i < N; i++) {
    sequence[cnt] = numbers[i];
    backtracking(i, cnt + 1);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> numbers[i];

  // 비내림차 수열을 만들기 쉽도록 오름차순으로 정렬한다
  sort(numbers, numbers + N);

  backtracking(0, 0);
}

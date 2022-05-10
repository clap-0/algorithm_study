#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int numbers[8];
int sequence[8];
bool isChosen[8];

// 백트래킹을 이용하여 길이가 M인 중복되지 않는 수열들을 출력하는 함수
void backtracking(int cnt) {
  // 수열이 완성된 경우 출력한다
  if(cnt == M) {
    for(int i = 0; i < M; i++) cout << sequence[i] << ' ';
    cout << '\n';
    return;
  }

  // 중복된 수열이 나오는 것을 방지하기 위해 이전에 cnt번째 수에 사용한 수와
  // 이번에 사용하는 수가 다른 경우에만 수열을 만든다
  int prevNum = 0;
  for(int i = 0; i < N; i++) 
    if(!isChosen[i] && prevNum != numbers[i]) {
      isChosen[i] = true;
      prevNum = numbers[i];
      sequence[cnt] = numbers[i];
      backtracking(cnt + 1);
      isChosen[i] = false;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> numbers[i];

  sort(numbers, numbers + N);

  backtracking(0);
}

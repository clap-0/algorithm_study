#include <iostream>
using namespace std;

int N, M;
int arr[8];

// 백트래킹을 이용해서 조건을 만족하는 길이가 M인 수열을 모두 출력한다
void backtracking(int curr = 1, int cnt = 0) {
  // 수열의 길이가 M인 경우 한 줄에 출력
  if(cnt == M) {
    for(int i = 0; i < cnt; i++) cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  // arr[i] <= arr[j] (i < j)를 만족하므로
  // curr부터 N까지 모든 경우의 수를 구한다
  for(int i = curr; i <= N; i++) {
    arr[cnt] = i;
    backtracking(i, cnt + 1);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;

  backtracking();
}

#include <iostream>
#include <cstring>

using namespace std;

int N;
int S[16];
bool usable[16];  // 수열 S에 등장시킬 수 있는 X[i] 값

// 숌 사이 수열 S를 구하는 함수이다.
// 조건을 만족하는 S를 찾으면 true, 못 찾으면 false를 반환한다.
bool findSeq(int cnt = 0)
{
  // 숌 사이 수열 S를 찾은 경우 true 반환
  if (cnt == N) {
    return true;
  }

  int idx = 0;
  while (S[idx] != -1) {  // 수열 S에서 아직 수가 채워지지 않은 가장 작은 인덱스를 구한다.
    ++idx;
  }

  // 숫자 num이 사용가능하고, S[nextIdx]에도 수가 채워지지 않은 경우
  // 수열 S에 숫자 num을 등장시키고, 재귀적으로 수열 S를 채운다.
  for (int num = 0, nextIdx = idx + 1; nextIdx < 2 * N; num++, nextIdx++) {  // num: 사용가능한 가장 작은 수
    if (usable[num] && S[nextIdx] == -1) {                                   // nextIdx: S에서 또다른 num이 등장할 인덱스
      usable[num] = false;
      S[idx] = S[nextIdx] = num;
      if (findSeq(cnt + 1)) {
        return true;
      }
      usable[num] = true;
      S[idx] = S[nextIdx] = -1;
    }
  }

  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int X;
    cin >> X;
    usable[X] = true;
  }
  memset(S, -1, sizeof(S));

  bool isFound = findSeq();
  if (!isFound) {
    cout << -1 << '\n';
  }
  else {
    for (int i = 0; i < N * 2; i++) {
      cout << S[i] << ' ';
    }
  }
}

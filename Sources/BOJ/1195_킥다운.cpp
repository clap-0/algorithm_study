#include <cstdio>
#include <algorithm>
using namespace std;

bool A[100], B[100];

int main()
{
  int N = 0, M = 0;
  char c;
  // 홈을 false, 이를 true로 하여 두 기어 파트에 대한 배열을 입력한다.
  while ((c = getchar()) != '\n')
    A[N++] = (c == '2');
  while ((c = getchar()) != '\n')
    B[M++] = (c == '2');

  // 첫 번째 기어가 항상 두 번째 기어보다 길거나 길이가 같도록 하여
  // 이후의 코드에서 배열의 bound 계산을 줄인다.
  if (N < M) {
    swap(N, M);
    swap(A, B);
  }

  int ans = N + M;
  // 첫 번째 기어의 앞부분과 두 번째 기어의 뒷부분이 맞물리는 경우를 찾는다.
  for (int k = 1; k < M; k++) { // k : 맞물리는 홈이나 이의 개수
    bool isEngaged = true;
    for (int i = 0; i < k; i++)
      if (A[i] & B[M - k + i]) {
        isEngaged = false;
        break;
      }
    if (isEngaged)
      ans = min(ans, N + M - k);
  }
  // 첫 번째 기어의 내부에 두 번째 기어가 맞물리거나 (N >= M 이므로)
  // 첫 번째 기어의 뒷부분에 두 번째 기어의 앞부분이 맞물리는 경우를 찾는다.
  for (int i = 0; i < N; i++) {
    bool isEngaged = true;
    for (int j = 0; j < M && i + j < N; j++)
      if (A[i + j] & B[j]) {
        isEngaged = false;
        break;
      }
    // 첫 기어 내부에 두 번째 기어가 맞물리는 경우 가로너비는 N이다.
    if (isEngaged)
      ans = min(ans, max(N, i + M));
  }
  
  printf("%d\n", ans);
}

#include <iostream>
using namespace std;

int N;
long long R, S, E;

// 왼쪽위가 top행 left열이고 크기가 2^k인 월쉬행렬에서 R행 [S..E]열의 수를 합한 값을 반환하는 함수 
int solve(long long top, long long left, int k)
{
  // 행렬의 크기가 1이면 1반환
  if (k == 0)
    return 1;
  
  int ret = 0;
  // size : 행렬의 크기, half = size / 2
  long long size = (1LL << k), half = size / 2LL;
  // 행렬을 4등분한 뒤, 각 사분면에 구하고자 하는 범위가 포함되면 재귀호출로 탐색한다.
  if (top <= R && R < top + half && !(E < left) && !(left + half <= S))
    ret += solve(top, left, k - 1);
  if (top <= R && R < top + half && !(E < left + half) && !(left + size <= S))
    ret += solve(top, left + half, k - 1);
  if (top + half <= R && R < top + size && !(E < left) && !(left + half <= S))
    ret += solve(top + half, left, k - 1);
  if (top + half <= R && R < top + size && !(E < left + half) && !(left + size <= S))
    ret -= solve(top + half, left + half, k - 1); // 월쉬행렬의 오른쪽 아래 행렬은 다른 부분행렬이 반전된 형태이므로 -1을 곱한 값을 더한다.
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  while (true)
  {
    cin >> N >> R >> S >> E;
    if (N == -1)
      break;
    cout << solve(0, 0, N) << '\n';
  }
}

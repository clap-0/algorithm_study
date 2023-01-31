#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[10000];

long long countTeams()
{
  long long ret = 0;
  int idx = 0;

  // idx번째 학생보다 실력이 좋고, 실력 합이 0이 되는
  // 나머지 두 팀원의 경우의 수를 두 포인터를 이용해 구한다.
  while (idx + 2 < N && A[idx] <= 0) {
    int lo = idx + 1, hi = N - 1;

    while (lo < hi) {
      int left = A[lo], right = A[hi];

      if (left + right + A[idx] == 0) { // 세 학생의 실력 합이 0인 경우
        if (left == right) {      // left와 right가 같으면,
          int cnt = hi - lo + 1;  // 경우의 수는 실력이 left(right)인 학생들 중 2명을 뽑는 경우이다.
          ret += cnt * (cnt - 1) / 2;
          break;
        }

        int leftCnt = 1, rightCnt = 1;  // left와 right가 다르면,
        while (A[++lo] == left) ++leftCnt;
        while (A[--hi] == right) ++rightCnt;
        ret += leftCnt * rightCnt;  // 경우의 수는 실력이 left인 학생 수 * 실력이 right인 학생 수이다.
      }
      else if (left + right + A[idx] < 0) ++lo;
      else --hi;
    }
    ++idx;
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> A[i];

  // 코딩 실력을 오름차순으로 정렬
  sort(A, A + N);

  cout << countTeams() << '\n';
}

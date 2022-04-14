#include <iostream>
#include <algorithm>
using namespace std;

long long A[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> A[i];

  sort(A, A + N);

  // 투 포인터 알고리즘
  int left = 0, right = 0;
  long long ans = 2000000001;
  while(left < N && ans > M) {
    if(A[right] - A[left] >= M) {
      ans = min(ans, A[right] - A[left]);
      ++left;
    }
    else ++right;
  }

  cout << ans << '\n';
}

#include <iostream>
#include <algorithm>
using namespace std;

int A[20000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
      cin >> A[i];
    sort(A, A + N);

    int ans = 0;
    for (int i = 0; i < M; i++) {
      int B;
      cin >> B;
      ans += upper_bound(A, A + N, B) - A;
    }
    ans = N * M - ans;
    
    cout << ans << '\n';
  }
}

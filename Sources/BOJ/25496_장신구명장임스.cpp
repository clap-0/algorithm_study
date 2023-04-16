#include <iostream>
#include <algorithm>
using namespace std;

int A[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int P, N;
  cin >> P >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A + N);

  int ans = 0;
  for (int i = 0; i < N && P < 200; i++) {
    P += A[i];
    ++ans;
  }

  cout << ans << '\n';
}

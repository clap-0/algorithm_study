#include <iostream>
using namespace std;

int main()
{
  string A, B;
  cin >> A >> B;

  int asize = A.size(), N = B.size() - asize;
  int ans = B.size();
  for (int i = 0; i <= N; i++) {
    int diff = 0;
    for (int j = 0; j < asize; j++)
      if (A[j] != B[i + j])
        ++diff;
    ans = min(ans, diff);
  }

  cout << ans << '\n';
}

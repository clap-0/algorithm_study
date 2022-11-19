#include <iostream>
#include <vector>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N;
    string A, B;
    cin >> N >> A >> B;

    int cntB = 0, cntW = 0;
    for (int i = 0; i < N; i++)
      if (A[i] != B[i]) {
        A[i] == 'B' ? ++cntB : ++cntW;
      }
    cout << abs(cntB - cntW) + min(cntB, cntW) << '\n';
  }
}

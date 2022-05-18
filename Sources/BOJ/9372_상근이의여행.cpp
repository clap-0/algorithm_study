#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
      int A, B;
      cin >> A >> B;
    }
    cout << N - 1 << '\n';
  }
}

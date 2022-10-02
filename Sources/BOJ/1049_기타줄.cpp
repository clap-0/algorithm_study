#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N, M;
  cin >> N >> M;
  
  int package = 1000, piece = 1000;
  for (int i = 0; i < M; i++) {
    int price1, price2;
    cin >> price1 >> price2;
    package = min(package, price1);
    piece = min(piece, price2);
  }

  int ans = min((N / 6) * package + (N % 6) * piece, min((N / 6 + 1) * package, N * piece));
  cout << ans << '\n';
}

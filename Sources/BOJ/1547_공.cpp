#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  bool hasBall[3] = {true, false, false};
  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    swap(hasBall[a - 1], hasBall[b - 1]);
  }

  int ans = -1;
  for (int i = 0; i < 3; i++)
    if (hasBall[i]) {
      ans = i + 1;
      break;
    }
  cout << ans << '\n';
}

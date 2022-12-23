#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int ans = 0;
    for (int j = 0; j < N; j++) {
      int num;
      cin >> num;
      ans |= num;
    }
    cout << ans << ' ';
  }
}

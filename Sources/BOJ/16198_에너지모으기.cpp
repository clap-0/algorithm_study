#include <iostream>
using namespace std;

int N;
int W[10];
bool isChoosed[10];

int solve()
{
  int ret = 0;
  for (int i = 1; i < N - 1; i++) {
    if (isChoosed[i]) {
      continue;
    }
    int left = i - 1, right = i + 1;
    while (isChoosed[left]) --left;
    while (isChoosed[right]) ++right;

    isChoosed[i] = true;
    ret = max(ret, W[left] * W[right] + solve());
    isChoosed[i] = false;
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> W[i];
  }

  cout << solve() << '\n';
}

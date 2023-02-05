#include <iostream>
using namespace std;

int N, K;
int X[1000000];

bool isAchievable(int T)
{
  long long required = 0LL;
  for (int i = 0; i < N; i++) {
    required += max(0, T - X[i]);
    if (required > K)
      return false;
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> K;
  for (int i = 0; i < N; i++)
    cin >> X[i];

  int ans;
  long long lo = 0, hi = 2e9;
  while (lo <= hi) {
    int mid = (lo + hi) / 2LL;
    if (isAchievable(mid)) {
      ans = mid;
      lo = mid + 1;
    }
    else
      hi = mid - 1;
  }

  cout << ans << '\n';
}

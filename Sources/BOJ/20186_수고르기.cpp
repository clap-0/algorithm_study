#include <iostream>
#include <algorithm>
using namespace std;

int scores[5000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> scores[i];
  }
  sort(scores, scores + N, greater<int>());

  int ans = -K * (K - 1) / 2;
  for (int i = 0; i < K; i++) {
    ans += scores[i];
  }

  cout << ans << '\n';
}

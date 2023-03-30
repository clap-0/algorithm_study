#include <iostream>
#include <algorithm>
using namespace std;

int quests[300000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> quests[i];
  }

  // 활성화된 아케인스톤이 많을수록, 얻는 경험치가 많아지므로
  // 주는 경험치가 적은 퀘스트부터 수행해 아케인스톤을 모은다.
  sort(quests, quests + n);

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += 1LL * quests[i] * min(k, i);
  }
  cout << ans << '\n';
}

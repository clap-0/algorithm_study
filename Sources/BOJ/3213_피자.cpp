#include <iostream>
#include <cmath>
using namespace std;

int cnt[3];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) { // 각 피자의 양마다, 해당 양만큼 먹을 수 있는 친구들의 수를 구한다.
    string str;
    cin >> str;
    if (str[2] == '2') {
      cnt[1]++;
    }
    else {
      cnt[str[0] == '1' ? 0 : 2]++;
    }
  }

  int ans = 0;

  ans += cnt[2];  // 3/4 조각을 먹는 친구들은 무조건 한 판씩 있어야 한다.
  cnt[0] -= min(cnt[0], cnt[2]);  // 1/4 조각을 먹는 친구랑 3/4 조각을 먹는 친구랑 나눠 먹을 수 있다.

  ans += cnt[1] / 2;  // 1/2 조각을 먹는 친구들은 피자 반 판씩 나눠먹는다.
  ans += cnt[0] / 4;  // 1/4 조각을 먹는 친구들은 피자 1/4 판씩 나눠먹는다.
  ans += ceil((cnt[1] % 2 + cnt[0] % 4) / 4.0); // 1/2 조각을 먹는 친구들과 1/4 조각을 먹는 친구들이 남는 경우, 같이 먹는다.

  cout << ans << '\n';
}

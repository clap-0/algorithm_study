#include <iostream>
using namespace std;

int N, M;
int costs[100000];

// 용돈을 K원씩 인출할 때, N일 동안 필요한 최소 인출횟수를 반환한다.
int countWithdrawing(int K)
{
  int ret = 0;
  int money = 0;
  for (int i = 0; i < N; i++) {
    if (money < costs[i]) {
      money = K;
      ++ret;
    }
    money -= costs[i];
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  int maxCost = 0;
  for (int i = 0; i < N; i++) {
    cin >> costs[i];
    maxCost = max(costs[i], maxCost);
  }
  
  int ans;
  int lo = maxCost, hi = 1e9;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (countWithdrawing(mid) <= M) {
      ans = mid;
      hi = mid - 1;
    }
    else
      lo = mid + 1;
  }

  cout << ans << '\n';
}

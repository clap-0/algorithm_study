#include <iostream>
#include <queue>
using namespace std;

const int MOD = 1000000007;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int N;
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    cin >> N;
    for(int i=0; i<N; i++) {
      long long C;
      cin >> C;
      pq.push(C);
    }

    // 작은 것끼리 곱하는 것을 반복한다
    long long ans = 1LL;
    while(pq.size() > 1) {
      long long slime1 = pq.top(); pq.pop();
      long long slime2 = pq.top(); pq.pop();
      long long merged = slime1 * slime2 % MOD;
      ans = ans * merged % MOD;
      pq.push(slime1 * slime2);
    }
    cout << ans << '\n';
  }
}

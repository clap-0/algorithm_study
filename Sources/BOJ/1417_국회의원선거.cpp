#include <iostream>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, poll;
  priority_queue<int> pq;
  cin >> N >> poll;
  for (int i = 1; i < N; i++) {
    int p;
    cin >> p;
    pq.push(p);
  }

  int ans = 0;
  while (!pq.empty() && pq.top() >= poll) {
    int tmp = pq.top();
    pq.pop();
    pq.push(tmp - 1);
    ++poll;
    ++ans;
  }
  cout << ans << '\n';
}

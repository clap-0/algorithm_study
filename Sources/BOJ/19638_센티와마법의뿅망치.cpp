#include <iostream>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, H, T;
  priority_queue<int> pq;
  cin >> N >> H >> T;
  for(int i=0; i<N; i++) {
    int L;
    cin >> L;
    pq.push(L);
  }

  int cnt = 0;
  for(int i=0; i<T; i++) {
    int curr = pq.top();
    if (curr < H || curr == 1) break;
    pq.pop();
    pq.push(curr / 2);
    ++cnt;
  }

  if(pq.top() < H) {
    cout << "YES\n" << cnt << '\n';
  }
  else {
    cout << "NO\n" << pq.top() << '\n';
  }
}

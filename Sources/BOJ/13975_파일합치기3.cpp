#include <iostream>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int K;
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    cin >> K;
    for(int i=0; i<K; i++) {
      int num;
      cin >> num;
      pq.push(num);
    }
    
    // 작은 파일끼리 합치는 것을 반복한다
    long long ans = 0;
    while(pq.size() > 1) {
      long long a = pq.top(); pq.pop();
      long long b = pq.top(); pq.pop();
      ans += a + b;
      pq.push(a + b);
    }
    cout << ans << '\n';
  }
}

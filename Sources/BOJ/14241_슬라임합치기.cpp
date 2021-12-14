#include <iostream>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  priority_queue<int> pq;
  cin >> N;
  for(int i=0; i<N; i++){
    int slime;
    cin >> slime;
    pq.push(slime);
  }

  int ans=0;
  while(pq.size() > 1){
    int x = pq.top(); pq.pop();
    int y = pq.top(); pq.pop();
    ans += x*y;
    pq.push(x+y);
  }
  cout << ans << '\n';
}

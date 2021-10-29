#include <iostream>
#include <queue>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N, M;
    queue<pair<int,int> > Q;
    // 남은 문서중 가장 높은 중요도를 쉽게 구할 수 있게 우선순위큐 사용
    priority_queue<int> pq;
    cin >> N >> M;
    for(int i=0; i<N; i++){
      int priority;
      cin >> priority;
      Q.push({priority, i});
      pq.push(priority);
    }
    int ans=0;
    while(!Q.empty()){
      pair<int,int> curr=Q.front();
      Q.pop();
      // 큐의 가장 앞에 있는 문서의 중요도가 가장 높다면 바로 인쇄한다
      if(curr.first==pq.top()){
        ans++;
        pq.pop();
        // 인쇄한 문서가 M이라면 반복문 종료
        if(curr.second==M) break;
      }
      else Q.push(curr);
    }
    cout << ans << '\n';
  }
}

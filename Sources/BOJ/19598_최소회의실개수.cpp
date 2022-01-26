#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

pair<int,int> schedules[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> schedules[i].first >> schedules[i].second;
  
  sort(schedules, schedules+N);
  
  // 우선순위큐를 이용하여 회의실의 개수가 최소가 되도록 회의를 구성할 때
  // 각 회의실의 회의가 끝나는 시간을 오름차순으로 저장한다
  priority_queue<int, vector<int>, greater<int> > pq;
  pq.push(schedules[0].second);
  
  // 다음 회의의 시작 시간보다 끝나는 시간이 작거나 같은 회의실 중 가장 빨리 끝나는 회의실에서 다음 회의를 진행한다
  // 만약 그러한 회의실이 없다면 새로운 회의실을 추가한다
  for(int i=1; i<N; i++) {
    if(pq.top() <= schedules[i].first) pq.pop();
    pq.push(schedules[i].second);
  }
  cout << pq.size() << '\n';
}

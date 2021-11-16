#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
pair<int,int> lessons[200000];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> lessons[i].first >> lessons[i].second;
  sort(lessons, lessons+N);
  // 사용 중인 강의실의 강의가 끝나는 시간 저장
  priority_queue<int, vector<int>, greater<int> > pq;
  pq.push(lessons[0].second);
  for(int n=1; n<N; n++){
    // 빈 강의실이 있는 경우 해당 강의실에서 이번 n번 강의를 한다
    if(pq.top() <= lessons[n].first) pq.pop();
    // 빈 강의실이 없는 경우 추가로 강의실 
    pq.push(lessons[n].second);
  }
  cout << pq.size() << '\n';
}

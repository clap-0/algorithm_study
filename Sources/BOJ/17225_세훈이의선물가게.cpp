#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int A, B, N;
  // 선물의 포장시작시간과 포장지의 색을 우선순위큐에 저장한다
  priority_queue<pair<int,char>, vector<pair<int,char> >,  greater<pair<int,char> > > pq;
  cin >> A >> B >> N;
  // 기존 선물 포장이 끝난 후에야 다음 선물을 포장할 수 있으므로
  // 지금 진행중인 포장이 끝나는 가장 마지막 시간을 저장해놓는다
  int bTime=-1, rTime=-1;
  for(int i=0; i<N; i++){
    int t, m;
    char c;
    cin >> t >> c >> m;
    if(c=='B'){
      // 주문받은 시간에도 포장이 진행중인 경우
      // 마지막 포장이 끝난 후에 지금 주문받은 선물 포장을 한다
      if(t<bTime) t=bTime;
      for(int j=0; j<m; j++) pq.push({t+A*j, c});
      // 지금 주문받은 선물이 모두 포장이 끝나는 시간으로 최신화시킨다
      bTime=t+A*m;
    }
    else {
      if(t<rTime) t=rTime;
      for(int j=0; j<m; j++) pq.push({t+B*j, c});
      rTime=t+B*m;
    }
  }
  // 포장을 시작한 순서에 따라 번호를 매긴다
  vector<int> blue, red;
  int gift=1;
  while(!pq.empty()){
    char color=pq.top().second;
    pq.pop();
    if(color=='B') blue.push_back(gift++);
    else red.push_back(gift++);
  }
  // 출력
  cout << blue.size() << '\n';
  for(int b : blue) cout << b << ' ';
  cout << '\n';
  cout << red.size() << '\n';
  for(int r : red) cout << r << ' ';
}

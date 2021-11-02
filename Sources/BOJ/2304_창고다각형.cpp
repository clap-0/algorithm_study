#include <iostream>
#include <queue>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  priority_queue<pair<int,int> > pq;
  cin >> N;
  for(int i=0; i<N; i++){
    int L, H;
    cin >> L >> H;
    pq.push({H, L});
  }
  // 높이에 대하여 내림차순으로 기둥을 확인하며
  // 해당 기둥이 지금까지 만든 창고다각형의 양쪽 맨끝 [left, right]의 범위밖인 경우 넓이를 계산해 더한다
  int left=pq.top().second, right=left+1, ans=pq.top().first;
  pq.pop();
  while(!pq.empty()){
    int L=pq.top().second, H=pq.top().first;
    pq.pop();
    if(L<left){
      ans += (left-L)*H;
      left = L;
    }
    else if(right<L+1){
      ans += (L+1-right)*H;
      right = L+1;
    }
  }
  cout << ans << '\n';
}

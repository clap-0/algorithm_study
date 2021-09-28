#include <iostream>
#include <stack>
using namespace std;
int reception[500000], height[500000];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  stack<pair<int,int> > stk;
  cin >> N;
  for(int i=0; i<N; i++) cin >> height[i];
  for(int i=N-1; i>0; i--){
    // 아직 자신의 신호가 수신되지 못한 탑들에 대해 i-1번 탑이 수신하는지 확인한다.
    while(!stk.empty()&&stk.top().first<=height[i-1]){
      reception[stk.top().second]=i;
      stk.pop();
    }
    if(height[i]<=height[i-1]) reception[i]=i;
    else stk.push({height[i], i});
  }
  for(int i=0; i<N; i++) cout << reception[i] << ' ';
}

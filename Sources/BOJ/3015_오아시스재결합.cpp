#include <iostream>
#include <stack>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  long long ans = 0;
  // 기다리는 사람의 키 height에 대하여
  // { height, i번 사람을 포함한 i번보다 앞에 있고 height보다 키가 작거나 같은 사람들을 사이에 둔 키가 height인 사람들의 수 }를
  // 순감소되도록 스택에 넣는다
  stack<pair<int,int> > stk;
  for(int i = 0; i < N; i++) {
    int height;
    cin >> height;
    
    // last : 가장 마지막으로 스택에서 삭제한 사람 정보
    pair<int,int> last = {0, 0};
    while(!stk.empty() && stk.top().first <= height) {
      last = stk.top();
      ans += last.second;
      stk.pop();
    }
    
    // 스택이 비어있지 않은 경우 i번 사람보다 앞에 있는 height보다 큰 사람과 마주볼 수 있다
    if(!stk.empty()) ++ans;
    
    if(last.first == height) stk.push({height, last.second + 1});
    else stk.push({height, 1});
  }
  cout << ans << '\n';
}

#include <iostream>
#include <stack>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  // 기다리는 사람의 키 height와
  // [0..i-1] 범위에서, 키가 height이고 i번 사람과 서로 볼 수 있는 사람 수 + 1(i번 자기자신) 쌍을
  // height에 대해 순감소되도록 스택에 넣는다.
  stack<pair<int,int> > stk;
  long long ans = 0;
  
  // A와 B 사이에 두 사람 모두보다 키가 큰 사람이 없는 경우에만 서로 볼 수 있다.
  for(int i = 0; i < N; i++) {
    int height;
    cin >> height;
    
    // last : 가장 마지막으로 스택에서 삭제한 사람 정보
    pair<int,int> last = {0, 0};
    
    while(!stk.empty() && stk.top().first <= height) {  // height과 키가 같은 사람들을 한 번에 관리하기 위해 '<=' 를 사용했다.
      last = stk.top();
      ans += last.second;
      stk.pop();
    }
    
    // 스택이 비어있지 않은 경우 i번 사람보다 앞에 있는 height보다 큰 사람과 마주볼 수 있다
    if(!stk.empty()) ++ans;
    
    // height과 키가 같은 사람들을 위의 while문에서 삭제 후 한 번에 관리한다.
    if(last.first == height) stk.push({height, last.second + 1});
    else stk.push({height, 1});
  }
  cout << ans << '\n';
}

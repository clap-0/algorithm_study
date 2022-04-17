#include <iostream>
#include <stack>
using namespace std;

stack<pair<int,int> > stk;
// NGE[i] = i번째 원소의 오큰수
int NGE[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) {
    int A;
    cin >> A;
    
    // 스택 내부의 원소들이 내림차순이 되도록 스택에 수를 넣는다
    // 스택상에서 A보다 작은 원소들의 오큰수는 A이다
    while(!stk.empty() && stk.top().first < A) {
      NGE[stk.top().second] = A;
      stk.pop();
    }
    stk.push({A, i});
  }

  // 스택에 남아있는 원소들은 오른쪽에 자기보다 큰 수가 없는 수들이므로
  // 오큰수가 -1이다
  while(!stk.empty()) {
    NGE[stk.top().second] = -1;
    stk.pop();
  }

  for(int i = 0; i < N; i++) cout << NGE[i] << " ";
}

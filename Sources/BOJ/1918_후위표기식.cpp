#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// 스택 안에 있을 때의 우선순위(In-Stack Priority)인 ISP와
// 스택 밖에 있을 때의 우선순위(Incomming Priority)인 ICP
unordered_map<char,int> ISP, ICP;

void initPriority() {
  ISP['*'] = ICP['*'] = ISP['/'] = ICP['/'] = 2;
  ISP['+'] = ICP['+'] = ISP['-'] = ICP['-'] = 3;
  // '('는 스택 안에 있을 때 우선순위가 가장 낮고, 밖에 있을 때는 우선순위가 가장 높다
  ISP['('] = 8; ICP['('] = 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string expression;
  cin >> expression;

  initPriority();

  stack<char> operators;
  for(char opr : expression) {
    // opr이 피연산자인 경우 바로 출력
    if('A' <= opr && opr <= 'Z') cout << opr;
    
    // opr이 ')'인 경우 스택에서 '('이 나올 때까지 모두 출력
    else if(opr == ')') {
      while(!operators.empty() && operators.top() != '(') {
        cout << operators.top();
        operators.pop();
      }
      operators.pop();
    }
    
    // opr의 우선순위보다 낮거나 같은 스택의 모든 연산자들을 출력 후 스택에 opr 추가
    else {
      while(!operators.empty() && ISP[operators.top()] <= ICP[opr]) {
        cout << operators.top();
        operators.pop();
      }
      operators.push(opr);
    }
  }

  // 스택에 남아있는 모든 연산자들을 출력
  while(!operators.empty()) {
    cout << operators.top();
    operators.pop();
  }
}

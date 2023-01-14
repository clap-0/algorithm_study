#include <iostream>
#include <stack>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int M;
  string initial;
  cin >> initial >> M;

  // 커서 왼쪽과 오른쪽에 있는 문자열들을 스택에 보관한다.
  stack<char> left, right;
  for (char ch : initial)
    left.push(ch);

  while (M--) {
    char cmd;
    cin >> cmd;
    switch (cmd) {
      case 'L' :
        if (!left.empty()) {
          right.push(left.top());
          left.pop();
        }
        break;
      case 'D' :
        if (!right.empty()) {
          left.push(right.top());
          right.pop();
        }
        break;
      case 'B' :
        if (!left.empty())
          left.pop();
        break;
      case 'P' :
        char ch;
        cin >> ch;
        left.push(ch);
        break;
    }
  }

  while (!left.empty()) {
    right.push(left.top());
    left.pop();
  }

  while (!right.empty()) {
    cout << right.top();
    right.pop();
  }
}

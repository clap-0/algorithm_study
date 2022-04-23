#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  getline(cin, str);
  
  int i = 0, N = str.length();
  stack<char> stk;
  while(i < N)
    // 공백인 경우, 출력하고 다음 문자로 넘어간다
    if(str[i] == ' ') cout << str[i++];
  
    // 태그의 시작점인 경우, 끝점까지 출력한다
    else if(str[i] == '<')
      do cout << str[i]; while(str[i++] != '>');
  
    // 단어인 경우, 역순으로 출력한다
    else {
      do stk.push(str[i++]); while(i < N && str[i] != ' ' && str[i] != '<');
      while(!stk.empty()) {
        cout << stk.top();
        stk.pop();
      }
    }
}

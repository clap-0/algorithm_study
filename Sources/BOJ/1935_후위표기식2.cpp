#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
  int n;
  int value[26];
  string postfix;
  stack<double> stk;
  cin >> n >> postfix;
  for(int i=0; i<n; i++) cin >> value[i];
  for(auto &p : postfix){
    if(p>='A'&&p<='Z') stk.push(value[p-'A']);
    else{
      double x=stk.top(); stk.pop();
      double y=stk.top(); stk.pop();
      switch(p){
        case '+' :
        stk.push(y+x);
        break;
        case '-' :
        stk.push(y-x);
        break;
        case '*' :
        stk.push(y*x);
        break;
        case '/' :
        stk.push(y/x);
        break;
      }
    }
  }
  printf("%.2lf\n", stk.top());
}

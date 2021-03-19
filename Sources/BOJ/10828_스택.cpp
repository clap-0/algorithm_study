#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
  int n;
  string order;
  vector<int> stack;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> order;
    if(order == "push"){
      int x;
      cin >> x;
      stack.push_back(x);
    }
    else if(order == "pop"){
      if(stack.empty()) cout << -1 << endl;
      else {
        cout << stack.back() << endl;
        stack.pop_back();
      }
    }
    else if(order == "size"){
      cout << stack.size() << endl;
    }
    else if(order == "empty"){
      cout << stack.empty() << endl;
    }
    else if(order == "top"){
      if(stack.empty()) cout << -1 << endl;
      else cout << stack.back() << endl;
    }
  }
  return 0;
}

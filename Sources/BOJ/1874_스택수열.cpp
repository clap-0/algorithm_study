#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;
string ans;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  int cnt = 1;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    while (stk.empty() || stk.top() < num) {
      stk.push(cnt++);
      ans.append("+\n");
    }
    if (stk.top() > num) {
      cout << "NO\n";
      return 0;
    }
    stk.pop();
    ans.append("-\n");
  }

  cout << ans;
}

#include <iostream>
#include <stack>
using namespace std;

int h[80000];
stack<int> stk;

int main()
{
  int N;
  long long ans = 0LL;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> h[i];

  for (int i = 0; i < N; i++) {
    while (!stk.empty() && stk.top() <= h[i]) 
      stk.pop();
    ans += stk.size();
    stk.push(h[i]);
  }

  cout << ans << '\n';
}

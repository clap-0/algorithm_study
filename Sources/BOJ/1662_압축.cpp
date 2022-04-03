#include <iostream>
using namespace std;

string S;
bool visited[50];

int dfs(int curr) {
  int len = 0;
  for(int next = curr; next < S.length(); next++) 
    if(!visited[next]) {
      visited[next] = true;
      if(S[next] == '(') {
        int num = S[next - 1] - '0';
        len += num * dfs(next + 1) - 1;
      }
      else if(S[next] == ')') return len;
      else ++len;
    }
  return len;
}

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> S;
  cout << dfs(0) << '\n';
}

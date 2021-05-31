#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#include <functional>
using namespace std;

const int MAX=10000;
const string COMMAND="DSLR";

function<int(int)> f[4]={ //네 명령어 D,S,L,R
  [](int n){return (n*2)%MAX;},
  [](int n){return (n==0 ? 9999 : n-1);},
  [](int n){return (n*10)%MAX+n/1000;},
  [](int n){return n/10+(n%10)*1000;}
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int a, b;
    queue<int> q;
    int prev[MAX]; //a를 루트로 하는 bfs스패닝트리상에서 부모노드의 값
    char cmd[MAX]; //cmd[i] = i로 만들기 위해 이전 상태에서 누른 명령어
    memset(prev, -1, sizeof(prev));
    cin >> a >> b;
    q.push(a);
    prev[a]=a;
    while(!q.empty()){
      int curr = q.front(); q.pop();
      if(curr==b) break;
      for(int i=0; i<4; i++){
        int next = f[i](curr);
        if(prev[next]!=-1) continue;
        cmd[next] = COMMAND[i];
        prev[next]=curr;
        q.push(next);
      }
    }
    stack<char> stk;
    int tmp=b;
    while(tmp!=a){
      stk.push(cmd[tmp]);
      tmp = prev[tmp];
    }
    while(!stk.empty()){
      cout << stk.top();
      stk.pop();
    }
    cout << '\n';
  }
}

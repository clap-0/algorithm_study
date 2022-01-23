#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// endNode[i] = i번 노드가 가리키는 노드. 문제의 그래프가 방향성이 있는 단순그래프이므로 이렇게 표현했다
int endNode[101];
// visited[i] = i번 노드의 방문 여부
// finished[i] = DFS를 할 때 i번 노드를 매개변수로 하는 함수의 종료 여부
bool visited[101], finished[101];
stack<int> stk;
// cycles = 문제의 그래프 상에서 사이클에 포함되는 노드들의 집합
vector<int> cycles;

// 깊이우선탐색을 이용하여 사이클을 찾아내는 함수
void dfs(int here) {
  visited[here] = true;
  stk.push(here);
  
  int there = endNode[here];
  if(!visited[there]) dfs(there);
  // there이 방문한 적이 있지만 아직 매개변수로 하는 함수가 종료되지 않았다면
  // there에서 here까지 사이클이 존재한다
  else if(!finished[there]) {
    while(1) {
      int tmp = stk.top();
      stk.pop();
      cycles.push_back(tmp);
      if(tmp == there) break;
    }
  }
  finished[here] = true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i=1; i<=N; i++) cin >> endNode[i];

  for(int i=1; i<=N; i++)
    if(!visited[i]) dfs(i);
  
  sort(cycles.begin(), cycles.end());
  cout << cycles.size() << '\n';
  for(int cycle : cycles) cout << cycle << '\n';
}

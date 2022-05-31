#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int K;
  cin >> K;
  while(K--) {
    int V, E;
    cin >> V >> E;
    vector<vector<int> > adj(V + 1);
    vector<int> group(V + 1, -1);
    for(int i = 0; i < E; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    // 너비우선탐색을 이용하여 이분그래프 찾기
    bool ans = true;
    queue<int> Q;
    for(int v = 1; v <= V && ans; v++)
      if(group[v] == -1) {  // v가 그룹에 속하지 않은 경우
        Q.push(v);
        group[v] = 0;
        while(!Q.empty() && ans) {
          int here = Q.front(); Q.pop();
          // here과 인접한 그룹들은 here과 다른 그룹이 된다
          for(int there : adj[here])
            if(group[there] == -1) {
              group[there] = 1 - group[here];
              Q.push(there);
            }
            // here과 인접하지만 같은 그룹에 속하는 경우 이분그래프가 아니므로 종료시킨다
            else if(group[there] == group[here]) {
              ans = false;
              break;
            }
        }
      }

    cout << (ans ? "YES" : "NO") << '\n';
  }
}

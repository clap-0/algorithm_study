#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n + 1);  // 인접리스트
    vector<int> color(n + 1, -1); // 각 동그라미의 색상. 아직 색칠하지 않으면 -1, 색칠한 경우 0 또는 1.
    for(int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    // 넓이우선탐색을 이용해 이분그래프 찾기
    bool ans = true;
    queue<int> Q;
    for(int i = 1; i <= n && ans; i++)
      if(color[i] == -1) {
        Q.push(i);
        color[i] = 0;
        while(!Q.empty() && ans) {
          int here = Q.front(); Q.pop();
          // 현재 동그라미와 인접한 동그라미에 대하여 탐색
          for(int there : adj[here])
            // 아직 색칠하지 않은 동그라미인 경우 현재 동그라미와 색이 다르게 색칠
            if(color[there] == -1) {
              color[there] = 1 - color[here];
              Q.push(there);
            }
            // 이미 색칠된 동그라미인데 색상이 현재 동그라미와 같은 경우 이분그래프가 아님
            else if(color[there] == color[here]) {
              ans = false;
              break;
            }
        }
      }
    cout << (ans ? "possible" : "impossible") << '\n';
  }
}

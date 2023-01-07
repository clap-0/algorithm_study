#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int X[51], Y[51];
vector<int> adj[51];
bool visited[51];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, R, D;
  cin >> N >> R >> D >> X[0] >> Y[0];
  for (int i = 1; i <= N; i++) {
    cin >> X[i] >> Y[i];
    // 적과 탑들의 좌표를 바탕으로 인접리스트를 만든다.
    for (int j = 0; j < i; j++)
      if (pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2) <= R * R) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
  }

  double ans = 0.0;
  double energy = D;
  queue<int> Q;
  Q.push(0);
  visited[0] = true;
  while (!Q.empty()) {
    int qsize = Q.size();
    while (qsize--) {
      int here = Q.front();
      Q.pop();
      for (int there : adj[here])
        if (!visited[there]) {
          Q.push(there);
          visited[there] = true;
          ans += energy;
        }
    }
    energy /= 2;
  }

  cout << ans << '\n';
}

#include <iostream>
#include <vector>
using namespace std;

int goals[200001];
vector<int> adj[200001];
bool visited[200001];

// 트리에서 here번 정점의 부모 노드를 color색으로 칠한 경우,
// here번 정점을 루트로하는 서브트리를 칠하기 위해 정점을 최소 몇 번 칠해야 하는지 반환한다.
int getPaintCount(int here, int color)
{
  visited[here] = true;

  int ret = 0;
  if (goals[here] != color) { // here번 정점에 칠해야 하는 색과, 부모노드에 칠한 색이 다른 경우
    ++ret;                    // here번과 그 아래에 있는 모든 정점을 새로운 색으로 칠한다.
    color = goals[here];
  }

  for (int there : adj[here]) 
    if (!visited[there]) {
      ret += getPaintCount(there, color);
    }
  
  return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> goals[i];
  }
  for (int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // 트리의 루트(1번)부터 모든 하위 정점들이 하얀색이므로 color를 0으로 한다.
  cout << getPaintCount(1, 0) << '\n';
}

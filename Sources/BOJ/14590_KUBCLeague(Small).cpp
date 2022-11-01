#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[20];
bool visited[20];
vector<int> ans;

// 깊이우선탐색을 이용하여 꼬리를 무는 선수 나열을 구한다.
void dfs(int here)
{
  visited[here] = true;
  for (int there : adj[here])
    if (!visited[there])
      dfs(there);
  // 문제의 그래프가 방향그래프이고, 간선이 모든 노드 사이를 연결하기 때문에
  // here을 호출한 노드에서 다른 서브트리로 함수를 실행시켜도
  // 해당 서브트리의 리프노드에서 here로 연결된다.
  ans.push_back(here);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    {
      bool isWon;
      cin >> isWon;
      if (isWon)
        adj[i].push_back(j);
    }

  dfs(0);
  cout << ans.size() << '\n';
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] + 1 << ' ';
}

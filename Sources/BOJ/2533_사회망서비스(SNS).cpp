#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
vector<int> adj[1000001];

// here을 루트로 하는 서브트리에서
// { here이 얼리어답터인 경우 해당 트리의 얼리어답터의 수 , here이 일반인인 경우 해당 트리의 얼리어답터의 수 }를 구한다
pii dfs(int here, int parent) {
  pii ret = {1, 0};
  for(int there : adj[here])
    if(there != parent) {
      pii next = dfs(there, here);
      
      // here이 얼리어답터가 아닌 경우, 자식노드들은 모두 얼리어답터여야 한다
      ret.second += next.first;
      
      // here이 얼리어답터인 경우, 자식노드는 얼리어답터일 수도 있고 아닐 수도 있으므로 두 값 중 최솟값을 더한다
      ret.first += min(next.first, next.second);
    }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  pii ans = dfs(1, 0);
  cout << min(ans.first, ans.second) << '\n';
}

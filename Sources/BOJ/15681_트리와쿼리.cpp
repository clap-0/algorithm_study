#include <iostream>
#include <vector>
using namespace std;
int query[100001];
bool visited[100001];
vector<int> adj[100001];
//DFS를 이용하여 here을 루트로 하는 서브트리의 정점의 개수를 구한다
int dfs(int here){
  visited[here]=true;
  //자식노드를 루트로 하는 서브트리의 정점의 개수를 더한다
  for(int there : adj[here])
    if(!visited[there]) query[here]+=dfs(there);
  //루트도 정점 개수에 포함한다
  return ++query[here];
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, R, Q;
  cin >> N >> R >> Q;
  for(int i=0; i<N-1; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(R);
  for(int i=0; i<Q; i++){
    int q;
    cin >> q;
    cout << query[q] << '\n';
  }
}

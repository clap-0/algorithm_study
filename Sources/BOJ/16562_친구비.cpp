#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//트리를 이용한 유니온파인드 구현
struct UnionFind{
  vector<int> parent, rank, cost;
  UnionFind(int n): parent(n), rank(n,1), cost(n){
    for(int i=0; i<n; i++) parent[i]=i;
  }
  //u가 속한 트리의 루트 번호 반환
  int find(int u){
    if(parent[u]==u) return u;
    return parent[u] = find(parent[u]);
  }
  //u가 속한 트리와 v가 속한 트리 합치기
  void merge(int u, int v){
    u = find(u); v = find(v);
    if(u==v) return; //u와 v가 같은 집합에 속해있는 경우
    //항상 랭크가 더 큰 노드가 루트가 되도록 합친다
    if(rank[u]>rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u]==rank[v]) rank[v]++;
    //두 노드의 친구비 중 더 저렴한 것을 루트의 친구비로 한다
    cost[v] = min(cost[u], cost[v]);
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  UnionFind uf(n);
  for(int i=0; i<n; i++) cin >> uf.cost[i];
  for(int i=0; i<m; i++){
    int v, w;
    cin >> v >> w;
    uf.merge(v-1, w-1);
  }
  int leastCost=0;
  vector<bool> paid(n, false);
  for(int i=0; i<n; i++){
    int root = uf.find(i);
    if(paid[root]) continue;
    leastCost += uf.cost[root];
    paid[root] = true;
  }
  if(leastCost<=k) cout << leastCost << '\n';
  else cout << "Oh no" << '\n';
}

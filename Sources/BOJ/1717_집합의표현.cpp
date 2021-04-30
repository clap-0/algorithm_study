#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//트리를 이용한 상호배타적집합
struct DisjointSet{
  vector<int> parent, rank;
  DisjointSet(int n) : parent(n), rank(n,1){
    for(int i=0; i<n; i++) parent[i] = i;
  }
  //u가 속한 트리의 루트 번호 반환
  int find(int u){
    if(parent[u]==u) return u;
    return parent[u] = find(parent[u]);
  }
  //u가 속한 트리와 v가 속한 트리 합치기
  void merge(int u, int v){
    u = find(u); v = find(v);
    if(u==v) return; //u와 v가 이미 같은 트리인 경우
    //항상 랭크가 더 큰 노드가 부모가 되도록 합친다
    if(rank[u]>rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u]==rank[v]) rank[v]++;
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  DisjointSet ds(n+1);
  for(int i=0; i<m; i++){
    int order, a, b;
    cin >> order >> a >> b;
    if(order) cout << (ds.find(a)==ds.find(b) ? "YES" : "NO") << '\n';
    else ds.merge(a, b);
  }
}

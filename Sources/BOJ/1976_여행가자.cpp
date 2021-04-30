#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//유니온파인드
struct UnionFind{
  vector<int> parent, rank;
  UnionFind(int n) : parent(n), rank(n,1){
    for(int i=0; i<n; i++) parent[i] = i;
  }
  //u가 속한 트리의 루트번호 반환
  int find(int u){
    if(parent[u]==u) return u;
    return parent[u] = find(parent[u]);
  }
  //u가 속한 트리와 v가 속한 트리 합치기
  void merge(int u, int v){
    u = find(u); v = find(v);
    if(u==v) return; //u,v가 이미 같은 집합내에 있는 경우
    //항상 랭크가 높은 노드가 부모가 되도록 합친다
    if(rank[u]>rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u]==rank[v]) rank[v]++;
  }
};
//여행계획이 주어졌을 때 가능한 여행경로가 있는지 반환
bool canTravel(UnionFind& uf, vector<int>& plan){
  int m=plan.size(), root = uf.find(plan[0]-1);
  for(int i=1; i<m; i++)
    if(uf.find(plan[i]-1)!=root) return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
      bool connected;
      cin >> connected;
      if(connected) uf.merge(i, j); 
    }
  
  vector<int> plan(m);
  for(int i=0; i<m; i++) cin >> plan[i];
  cout << (canTravel(uf, plan) ? "YES" : "NO") << '\n';
}

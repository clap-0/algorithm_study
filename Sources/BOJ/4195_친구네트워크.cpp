#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
//트리를 이용한 유니온파인드
struct UnionFind{
  int no;
  unordered_map<string, int> name2no; //친구이름을 번호로 변환
  //각 노드의 부모노드와 랭크 저장. 루트의 부모는 해당 트리의 노드 개수를 음수로 저장
  vector<int> parent, rank;
  UnionFind(int n): parent(n*2, -1), rank(n*2, 1), no(0) {}
  //u가 속한 트리의 루트 번호 반환
  int find(int u){
    if(parent[u]<0) return u;
    return parent[u] = find(parent[u]);
  }
  //u가 속한 트리와 v가 속한 트리를 합치고, 합쳐진 트리의 노드 개수 반환
  int merge(int u, int v){
    u = find(u); v = find(v);
    if(u==v) return -parent[v]; //u와 v가 같은 집합에 속하는 경우 노드 개수 바로 반환
    //항상 랭크가 더 큰 노드가 루트가 되도록 합친다
    if(rank[u]>rank[v]) swap(u, v);
    if(rank[u]==rank[v]) rank[v]++;
    parent[v] += parent[u]; //노드의 개수 최신화
    parent[u] = v;
    return -parent[v];
  }
  int getNetworkSize(string u, string v){
    //처음 사귄 친구는 번호 저장
    if(name2no.find(u)==name2no.end()) name2no[u] = no++;
    if(name2no.find(v)==name2no.end()) name2no[v] = no++;
    return merge(name2no[u], name2no[v]);
  }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int F;
    cin >> F;
    UnionFind UF(F);
    for(int i=0; i<F; i++){
      string a, b;
      cin >> a >> b;
      cout << UF.getNetworkSize(a, b) << '\n';
    }
  }
}

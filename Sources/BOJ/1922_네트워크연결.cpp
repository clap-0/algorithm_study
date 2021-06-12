#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
//u가 속한 트리의 루트번호 반환
int find(int* uf, int n){
  if(uf[n]<0) return n;
  return uf[n]=find(uf, uf[n]);
}
//u가 속한 트리와 v가 속한 트리를 합친다
//u와 v가 같은 컴포넌트에 속한 경우 false반환
bool merge(int* uf, int u, int v){
  u=find(uf, u), v=find(uf, v);
  if(u==v) return false;
  if(uf[u]>uf[v]) swap(u, v);
  uf[u]+=uf[v];
  uf[v]=u;
  return true;
}
int main()
{
  int n, m, ans=0;
  int uf[1000];
  vector<pair<int, pair<int,int> > > edges;
  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    edges.push_back({c, {a-1,b-1}});
  }
  //크루스칼 알고리즘
  sort(edges.begin(), edges.end());
  fill(uf, uf+n, -1);
  for(int i=0; i<m; i++){
    int u=edges[i].second.first, v=edges[i].second.second;
    //u와 v가 다른 컴포넌트에 속한 경우 최소스패닝트리에 간선 (u,v)추가. (사이클 방지)
    if(merge(uf, u, v)) ans+=edges[i].first;
  }
  printf("%d\n", ans);
}

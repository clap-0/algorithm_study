#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int uf[1000];
//간선의 정보 저장
struct Edge{
  int u, v, d;
  Edge():Edge(-1,-1,0){}
  Edge(int _u, int _v, int _d):u(_u), v(_v), d(_d){}
  bool operator<(const Edge&o){return d<o.d;}
};
//유니온 파인드 알고리즘
//merge()에서 주어진 두 정점이 이미 합쳐져 있는 경우 false 반환
int find(int n){
  if(uf[n]<0) return n;
  return uf[n] = find(uf[n]);
}
bool merge(int u, int v){
  u=find(u); v=find(v);
  if(u==v) return false;
  uf[u]=v;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  char gender[1000];
  Edge e[10000];
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> gender[i];
  for(int i=0; i<M; i++){
    int u, v, d;
    cin >> u >> v >> d; u--; v--;
    //남초에서 여초로의 도로만 저장한다
    if(gender[u]==gender[v]) continue;
    e[i] = Edge(u,v,d);
  }
  //크루스칼의 최소스패닝트리 알고리즘
  sort(e, e+M);
  fill(uf, uf+N, -1);
  int length=0, cnt=0;
  for(int i=0; i<M; i++)
    if(merge(e[i].u, e[i].v)){
      length += e[i].d;
      if(++cnt==N-1) break;
    }
  //모든 학교를 연결하는 경로가 없는 경우 경로 상에 도로의 개수가 N-1보다 적다
  cout << (cnt==N-1 ? length : -1) << '\n';
}

#include <cstdio>
#include <algorithm>
using namespace std;
//간선에 대한 정보를 저장하는 구조체
struct Edge{
  int u, v, w;
  Edge() : Edge(-1,-1,0){}
  Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w){}
  bool operator <(const Edge&o){return w<o.w;}
};
//n이 속한 트리의 루트번호 반환
int find(int* uf, int n){
  if(uf[n]<0) return n;
  return uf[n]=find(uf, uf[n]);
}
//u가 속한 트리와 v가 속한 트리를 합친다.
//u와 v가 이미 같은 트리에 속하는 경우 false반환
bool merge(int* uf, int u, int v){
  u=find(uf, u), v=find(uf, v);
  if(u==v) return false;
  uf[u]+=uf[v];
  uf[v]=u;
  return true;
}

int main()
{
  int V, E, ans=0, cnt=0;
  int uf[10000];
  Edge e[100000];
  scanf("%d %d", &V, &E);
  for(int i=0; i<E; i++){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    e[i]=Edge(a-1,b-1,c);
  }
  //크루스칼 알고리즘
  sort(e, e+E);
  fill(uf, uf+V, -1);
  for(int i=0;;i++)
    //i번째 간선의 양 정점이 서로 다른 트리에 속한 경우
    //최소스패닝트리에 i번 간선을 추가함
    if(merge(uf, e[i].u, e[i].v)){
      ans+=e[i].w;
      //최소스패닝트리가 완성된 경우 종료
      if(++cnt==V-1) break;
    }
  printf("%d\n", ans);
}

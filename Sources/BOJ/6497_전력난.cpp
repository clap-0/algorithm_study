#include <cstdio>
#include <algorithm>
using namespace std;

int uf[200000];
//간선에 대한 정보 저장
struct Edge{
  int u, v, w;
  Edge():Edge(-1,-1,0){};
  Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w){}
  bool operator <(const Edge&o){return w<o.w;}
};
//n이 속한 트리의 루트번호 반환
int find(int n){
  if(uf[n]<0) return n;
  return uf[n]=find(uf[n]);
}
//u가 속한 트리와 v가 속한 트리 합치기
//이미 같은 트리에 속해있는 경우 false 반환
bool merge(int u, int v){
  u=find(u), v=find(v);
  if(u==v) return false;
  uf[v]=u;
  return true;
}

int main()
{
  int m, n;
  Edge e[200000];
  while(1){
    scanf("%d %d", &m, &n);
    if(m==0 && n==0) break;
    int ans=0, cnt=0;
    for(int i=0; i<n; i++){
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      e[i]=Edge(x,y,z);
      ans+=z;
    }
    //크루스칼 알고리즘
    sort(e, e+n);
    fill(uf, uf+m, -1);
    for(int i=0;;i++)
      if(merge(e[i].u, e[i].v)){
        ans-=e[i].w;
        if(++cnt==m-1) break;
      }
    printf("%d\n", ans);
  }
}

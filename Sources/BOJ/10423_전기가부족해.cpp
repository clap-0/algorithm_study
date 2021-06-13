#include <cstdio>
#include <algorithm>
using namespace std;

int uf[1000];
//간선 정보 저장
struct Edge{
  int u, v, w;
  Edge():Edge(-1,-1,0){}
  Edge(int _u, int _v, int _w):u(_u), v(_v), w(_w){}
  bool operator <(const Edge&o){return w<o.w;}
};
//n이 속한 트리의 루트번호 반환
int find(int n){
  if(uf[n]<0) return n;
  return uf[n]=find(uf[n]);
}
//u가 속한 트리와 v가 속한 트리 합치기
//이미 u와 v가 같은 트리에 속하면 false 반환
bool merge(int u, int v){
  u=find(u), v=find(v);
  if(u==v) return false;
  uf[v]=u;
  return true;
}

int main()
{
  int N, M, K, cnt=0, ans=0;
  //발전소가 있는 도시 번호
  int plant[1000];
  Edge e[101000];
  scanf("%d %d %d", &N, &M, &K);
  for(int i=0; i<K; i++) scanf("%d", &plant[i]);
  for(int i=0; i<M; i++){
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    e[i]=Edge(u-1,v-1,w);
  }
  //발전소끼리 가중치가 0인 간선으로 연결
  for(int i=0; i<K-1; i++) e[M+i]=Edge(plant[i]-1, plant[i+1]-1, 0);
  //크루스칼 알고리즘
  sort(e, e+M+K-1);
  fill(uf, uf+N, -1);
  for(int i=0;;i++)
    if(merge(e[i].u, e[i].v)){
      ans+=e[i].w;
      if(++cnt==N-1) break;
    }
  printf("%d\n", ans);
}

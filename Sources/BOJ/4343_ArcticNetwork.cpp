#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int uf[500];
//간선에 대한 정보 저장
struct Edge{
  int u, v;
  double w;
  Edge() : Edge(-1,-1,0) {}
  Edge(int _u, int _v, double _w) : u(_u), v(_v), w(_w) {}
  bool operator <(const Edge&o){return w<o.w;}
};
//n이 속한 트리의 루트번호 반환
int find(int n){
  if(uf[n]<0) return n;
  return uf[n]=find(uf[n]);
}
//u가 속한 트리와 v가 속한 트리 합치기
//u와 v가 이미 같은 트리에 속하면 false 반환
bool merge(int u, int v){
  u=find(u), v=find(v);
  if(u==v) return false;
  uf[v]=u;
  return true;
}

int main()
{
  int N;
  //정점의 x좌표와 y좌표 저장
  int v[500][2];
  Edge e[124750];
  scanf("%d", &N);
  while(N--){
    int S, P, eCnt=0, cnt=0;
    scanf("%d %d", &S, &P);
    for(int i=0; i<P; i++){
      scanf("%d %d", &v[i][0], &v[i][1]);
      for(int j=0; j<i; j++) e[eCnt++]=Edge(i, j, sqrt(pow(v[i][0]-v[j][0],2)+pow(v[i][1]-v[j][1],2)));
    }
    //크루스칼 알고리즘
    sort(e, e+eCnt);
    fill(uf, uf+P, -1);
    for(int i=0;;i++)
      if(merge(e[i].u, e[i].v) && ++cnt==P-S){
        printf("%.2lf\n", e[i].w);
        break;
      }
  }
}

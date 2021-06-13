#include <iostream>
#include <algorithm>
using namespace std;

//간선의 정보를 저장하는 구조체
struct Edge{
  int u, v, w;
  Edge():Edge(-1,-1,0){}
  Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w){}
  bool operator <(const Edge&o){return w<o.w;}
};

int uf[100000];
Edge e[1000000];

//n이 속한 트리의 루트번호 반환
int find(int n){
  if(uf[n]<0) return n;
  return uf[n]=find(uf[n]);
}

//u가 속한 트리와 v가 속한 트리 합치기
//u와 v가 이미 같은 트리에 속한 경우 false 반환
bool merge(int u, int v){
  u=find(u), v=find(v);
  if(u==v) return false;
  uf[v]=u;
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, cnt=0, ans=0;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    e[i]=Edge(a-1,b-1,c);
  }
  //크루스칼 알고리즘
  sort(e, e+m);
  fill(uf, uf+n, -1);
  for(int i=0;;i++)
    if(merge(e[i].u, e[i].v)){
      ans+=e[i].w;
      //(정점의 개수-2)번 수행하여 트리를 두 개로 나눈다
      if(++cnt==n-2) break;
    }
  cout << ans << '\n';
}

#include <iostream>
#include <cstring>
using namespace std;
int x[3000], y[3000], r[3000], uf[3000];
//유니온파인드 알고리즘
int find(int n){
  if(uf[n]<0) return n;
  return uf[n]=find(uf[n]);
}
void merge(int u, int v){
  u=find(u); v=find(v);
  uf[v]=u;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> x[i] >> y[i] >> r[i];
    memset(uf, -1, sizeof(uf));
    for(int u=0; u<N; u++)
      for(int v=u+1; v<N; v++){
        //u와 v가 이미 같은 그룹에 속한 경우 패스
        if(find(u)==find(v)) continue;
        //u와 v사이의 거리가 u와 v의 통신영역거리의 합보다 작거나 같은 경우(통신영역이 겹치는 경우), u와 v는 같은 그룹에 속한다
        if((x[u]-x[v])*(x[u]-x[v]) + (y[u]-y[v])*(y[u]-y[v]) <= (r[u]+r[v])*(r[u]+r[v])) merge(u, v);
      }
    int groups=0;
    for(int i=0; i<N; i++)
      if(uf[i]<0) groups++;
    cout << groups << '\n';
  }
}

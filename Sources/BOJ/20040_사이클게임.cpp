#include <iostream>
#include <cstring>
using namespace std;
//유니온파인드 알고리즘
int uf[500000];
int find(int n){
  if(uf[n]<0) return n;
  return uf[n]=find(uf[n]);
}
bool merge(int u, int v){
  u=find(u), v=find(v);
  if(u==v) return true;
  uf[v]=u;
  return false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  memset(uf, -1, sizeof(uf));
  for(int i=1; i<=m; i++){
    int u, v;
    cin >> u >> v;
    if(merge(u,v)){
      cout << i << '\n';
      return 0;
    }
  }
  cout << 0 << '\n';
}

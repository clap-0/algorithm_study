#include <iostream>
#include <cstring>
using namespace std;
//유니온파인드 알고리즘
//하나의 칸에서 다른 칸으로 가는 방법이 무조건 하나밖에 없으므로
//세이프존의 개수는 사이클의 개수와 같을 수 밖에 없다
int uf[1000000];
int find(int n){
  if(uf[n]<0) return n;
  return uf[n]=find(uf[n]);
}
void merge(int u, int v){
  u=find(u); v=find(v);
  if(u==v) return;
  uf[v]=u;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, M, ans=0;
  char dir;
  cin >> N >> M;
  memset(uf, -1, sizeof(uf));
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
      cin >> dir;
      merge(i*1000+j, (i+(dir=='U'?-1:(dir=='D'?1:0)))*1000+j+(dir=='L'?-1:(dir=='R'?1:0)));
    }
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      if(uf[i*1000+j]<0) ans++;
  cout << ans << '\n';
}

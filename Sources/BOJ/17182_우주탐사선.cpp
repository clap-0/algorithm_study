#include <cstdio>
using namespace std;
int n, k, ans=987654321;
int adj[10][10];
//모든 행성을 탐사하는 가능한 모든 경우 확인
//비트마스킹을 통해 현재 탐사한 행성들 목록을 status에 저장
void ana(int here, int status, int sum=0){
  //모든 행성을 전부 탐사한 경우 ans최신화
  if(status==(1<<n)-1 && ans>sum) ans=sum;
  for(int i=0; i<n; i++){
    //i번 행성을 아직 방문하지 않은 경우
    if((status & 1<<i)==0){
      status |= (1<<i);
      ana(i, status|1<<i, sum+adj[here][i]);
      status&=~(1<<i);
    }
  }
}
int main()
{
  scanf("%d %d", &n, &k);
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      scanf("%d", &adj[i][j]);
  //플로이드-와샬 알고리즘
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        if(adj[i][j]>adj[i][k]+adj[k][j]) adj[i][j]=adj[i][k]+adj[k][j];
  ana(k, 1<<k);
  printf("%d\n", ans);
}

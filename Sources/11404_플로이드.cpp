#include <iostream>
using namespace std;
int n, m;
const int MAX_N=101, INF=987654321;
int adj[MAX_N][MAX_N];
void floyd(){ //플로이드 알고리즘
  for(int k=1; k<=n; k++)
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(int i=1; i<=n; i++) //큰 값으로 초기화. 자기자신으로 가는 비용은 0
    for(int j=1; j<=n; j++)
      adj[i][j]=((i==j)?0:INF);
  for(int i=0; i<m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a][b]=min(c, adj[a][b]); //값을 이미 입력받았던 경우 더 작은 값으로 저장
  }
  floyd();
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++)
      cout << ((adj[i][j]!=INF) ? adj[i][j] : 0) << ' ';
    cout << '\n';
  }
}

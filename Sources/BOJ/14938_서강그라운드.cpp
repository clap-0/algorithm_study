#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=100, INF=987654321;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, r;
  int t[MAX];
  //adj[u][v] = u에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣음
  int adj[MAX][MAX];
  cin >> n >> m >> r;
  fill(&adj[0][0], &adj[n-1][n], INF);
  for(int i=0; i<n; i++) cin >> t[i];
  for(int i=0; i<r; i++){
    int a, b, l;
    cin >> a >> b >> l; a--; b--;
    adj[a][b] = adj[b][a] = l;
  }
  //플로이드-와샬 알고리즘
  for(int i=0; i<n; i++) adj[i][i]=0;
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++){
      if(adj[i][k]==INF) continue;
      for(int j=0; j<n; j++)
        adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
    }
  //얻을 수 있는 최대 아이템 개수 구하기
  int maxItems=0;
  for(int i=0; i<n; i++){
    int items=0;
    for(int j=0; j<n; j++)
      if(adj[i][j]<=m) items+=t[j];
    maxItems=max(maxItems, items);
  }
  cout << maxItems << '\n';
}

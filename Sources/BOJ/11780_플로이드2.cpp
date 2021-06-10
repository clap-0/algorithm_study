#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=100, INF=987654321;
//via[u][v] = u에서 v로 가는 최단경로가 경유하는 점 중 가장 번호가 큰 정점
int via[MAX][MAX];
//u에서 v로 가는 최단 경로를 계산해 path에 저장
void reconstruct(int u, int v, vector<int>& path){
  if(via[u][v]==-1){
    path.push_back(u);
    if(u!=v) path.push_back(v);
  }
  else{
    reconstruct(u, via[u][v], path);
    path.pop_back();
    reconstruct(via[u][v], v, path);
  }
}

int main()
{
  int n, m;
  int adj[MAX][MAX];
  scanf("%d %d", &n, &m);
  fill(&adj[0][0], &adj[n-1][n], INF);
  fill(&via[0][0], &via[n-1][n], -1);
  for(int i=0; i<m; i++){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    adj[a-1][b-1]=min(adj[a-1][b-1], c);
  }
  //플로이드-와샬 알고리즘
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++){
      if(adj[i][k]==INF) continue;
      for(int j=0; j<n; j++)
        if(adj[i][j]>adj[i][k]+adj[k][j]){
          adj[i][j]=adj[i][k]+adj[k][j];
          via[i][j]=k;
        }
    }
  for(int i=0; i<n; i++) adj[i][i]=INF;
  //i에서 j로 가는데 필요한 최소비용 출력
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      printf("%d ", adj[i][j]%INF);
    puts("");
  }
  //i에서 j로 가는 비용이 최소가 되는 경로 출력. 없으면 0 출력
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(adj[i][j]!=INF){
        vector<int> path;
        reconstruct(i, j, path);
        printf("%lu ", path.size());
        for(int p : path) printf("%d ", p+1);
        puts("");
      }
      else puts("0");
    }
  }
}

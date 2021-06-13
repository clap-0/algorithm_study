#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX=100;
const double INF=1e9;

int main()
{
  int n;
  double ans=0;
  //stars[i] = i번째 별의 좌표
  //minCost[i] = 트리에 인접한 간선 중 i에 닿는 최소간선의 가중치
  double stars[MAX][2], minCost[MAX];
  //added[i] = i번 정점이 최소스패닝트리에 추가되었는가
  bool added[MAX]={false};
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%lf %lf", &stars[i][0], &stars[i][1]);
  //프림 알고리즘
  fill(minCost, minCost+n, INF);
  //0번 정점을 시작점으로 한다
  minCost[0]=0;
  for(int iter=0; iter<n; iter++){
    //다음에 트리에 추가할 정점을 찾는다
    int u=-1;
    for(int i=0; i<n; i++)
      if(!added[i]&&(u==-1 || minCost[u]>minCost[i])) u=i;
    ans+=minCost[u];
    added[u]=true;
    //u와 트리에 아직 추가되지 않은 다른 정점들 사이의 간선을 검사한다
    for(int v=0; v<n; v++){
      if(added[v]) continue;
      double w=sqrt(pow(stars[u][0]-stars[v][0],2)+pow(stars[u][1]-stars[v][1],2));
      if(minCost[v]>w) minCost[v]=w;
    }
  }
  printf("%.2lf\n", ans);
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=100, INF=987654321;

int n, m;
//groupId[i] = i가 속한 그룹의 번호
//adj[i][j] = i와 j 사이의 의사전달시간. 의사전달이 불가능하면 INF.
int groupId[MAX], adj[MAX][MAX];
int groupCnt;

//깊이우선탐색을 통해 연결된 정점들을 하나의 그룹으로 묶는다
void dfs(int here){
  groupId[here]=groupCnt;
  for(int i=0; i<n; i++)
    if(adj[here][i]==1 && groupId[i]==-1) dfs(i);
}
//플로이드-와샬 알고리즘
void floyd(){
  for(int i=0; i<n; i++) adj[i][i]=0;
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++){
      if(adj[i][k]==INF) continue;
      for(int j=0; j<n; j++)
        adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  fill(&adj[0][0], &adj[n-1][n], INF);
  fill(groupId, groupId+n, -1);
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b; a--; b--;
    adj[a][b] = adj[b][a] = 1;
  }
  //모든 컴포넌트에 그룹번호를 부여한다
  for(int i=0; i<n; i++)
    if(groupId[i]==-1){
      dfs(i);
      groupCnt++;
    }
  //플로이드-와샬 알고리즘
  floyd();
  //각 그룹의 리더를 찾는다
  vector<pair<int,int> > leaders(groupCnt, {-1, INF});
  for(int i=0; i<n; i++){
    int temp=0, g=groupId[i];
    //i번 위원의 위원회내 다른 위원에 대한 의사전달시간의 최댓값 구함
    for(int j=0; j<n; j++)
      if(adj[i][j]!=INF) temp=max(temp, adj[i][j]);
    //i가 속한 그룹 리더의 의사전달시간보다 i의 의사전달시간이 더 빠르면 i가 리더!!
    if(leaders[g].second>temp) leaders[g]={i,temp};
  }
  sort(leaders.begin(), leaders.end());
  cout << groupCnt << '\n';
  for(int i=0; i<groupCnt; i++) cout << leaders[i].first+1 << '\n';
}

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX_N=2000, MAX_M=1000;
int aMatch[MAX_N], bMatch[MAX_M];
vector<int> adj[MAX_N];
bool visited[MAX_N];
bool dfs(int a){
  for(int b : adj[a]){
    if(visited[b]) continue;
    visited[b]=true;
    if(bMatch[b]==-1 || dfs(bMatch[b])){
      aMatch[a]=b;
      bMatch[b]=a;
      return true;
    }
  }
  return false;
}
int main()
{
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  for(int a=0; a<N; a++){
    int i;
    scanf("%d", &i);
    while(i--){
      int b;
      scanf("%d", &b); b--;
      adj[a].push_back(b);
      adj[a+N].push_back(b);
    }
  }
  int ans[2]={0};
  memset(aMatch, -1, sizeof(aMatch));
  memset(bMatch, -1, sizeof(bMatch));
  for(int a=0; a<N*2; a++){
    if(aMatch[a]==-1){
      memset(visited, 0, sizeof(visited));
      if(dfs(a)) ans[a/N]++;
    }
    if(ans[1]==K) break;
  }
  printf("%d\n", ans[0]+ans[1]);
}

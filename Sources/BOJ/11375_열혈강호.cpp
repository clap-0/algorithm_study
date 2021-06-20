#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAX_N=1000, MAX_M=1000;
//각 정점에 매칭된 상대 정점 번호
int aMatch[MAX_N], bMatch[MAX_M];
bool visited[MAX_N];
vector<int> adj[MAX_N];
//직원들 그룹A의 정점 a에서 할 일들 그룹B의 매칭되지 않은 정점으로 가는 경로 찾기
bool dfs(int a){
  visited[a]=true;
  for(int b : adj[a])
    if(bMatch[b]==-1 || (!visited[bMatch[b]]&&dfs(bMatch[b]))){
      aMatch[a]=b;
      bMatch[b]=a;
      return true;
    }
  return false;
}
int main()
{
  int N, M, ans=0;
  scanf("%d %d", &N, &M);
  for(int a=0; a<N; a++){
    int i;
    scanf("%d", &i);
    while(i--){
      int b;
      scanf("%d", &b);
      adj[a].push_back(b-1);
    }
  }
  //aMatch와 bMatch를 계산하고 최대 매칭의 크기를 구한다
  memset(aMatch, -1, sizeof(aMatch));
  memset(bMatch, -1, sizeof(bMatch));
  for(int a=0; a<N; a++)
    if(aMatch[a]==-1){
      memset(visited, 0, sizeof(visited));
      if(dfs(a)) ans++;
    }
  printf("%d\n", ans);
}

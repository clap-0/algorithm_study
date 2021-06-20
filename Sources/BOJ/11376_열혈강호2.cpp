#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAX=1000;
//각 정점과 매칭되는 상대 정점 번호
int aMatch[MAX*2], bMatch[MAX];
bool visited[MAX*2];
vector<int> adj[MAX*2];
//직원 그룹의 정점 a에서 할 일 그룹의 정점 중 아직 매칭되지 않은 정점과 연결되는 경로 찾기
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
      scanf("%d", &b); b--;
      adj[a*2].push_back(b);
      adj[a*2+1].push_back(b);
    }
  }
  memset(aMatch, -1, sizeof(aMatch));
  memset(bMatch, -1, sizeof(bMatch));
  for(int a=0; a<N*2; a++)
    if(aMatch[a]==-1){
      memset(visited, 0, sizeof(visited));
      if(dfs(a)) ans++;
    }
  printf("%d\n", ans);
}

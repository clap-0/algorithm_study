#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAX_N=100;
//각 정점과 매칭되는 상대 정점 번호
int aMatch[MAX_N], bMatch[MAX_N];
vector<int> adj[MAX_N];
bool visited[MAX_N];
//학생 그룹 A의 정점 a와 노트북 그룹 B의 매칭되지 않은 정점 매칭하고 성공여부 반환
bool dfs(int a){
  for(int b : adj[a]){
    if(visited[b]) continue;
    visited[b]=true;
    //b가 아직 매칭되지 않았거나
    //b와 전에 매칭된 정점에서 다른 B의 정점과 매칭이 된 경우
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
  int N, M;
  scanf("%d %d", &N, &M);
  for(int i=0; i<M; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    adj[a-1].push_back(b-1);
  }
  memset(aMatch, -1, sizeof(aMatch));
  memset(bMatch, -1, sizeof(bMatch));
  int ans=0;
  for(int a=0; a<N; a++)
    if(aMatch[a]==-1){
      memset(visited, 0, sizeof(visited));
      if(dfs(a)) ans++;
    }
  printf("%d\n", ans);
}

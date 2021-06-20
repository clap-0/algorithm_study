#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MAX=1000;
//각 정점의 매칭된 상대 정점 번호
int match1[MAX], match2[MAX];
bool visited[MAX];
vector<int> adj[MAX];
//학생들 그룹A의 정점 a1에서 책 그룹B의 매칭되지 않은 정점으로 가는 경로 찾기
bool dfs(int a1){
  visited[a1]=true;
  //b1이 아직 매칭되지 않았거나
  //b1의 매칭된 상대정점에서 다른 매칭되지 않은 정점으로 가는 경로가 있는 경우 a1과 b1매칭
  for(int b1 : adj[a1])
    if(match2[b1]==-1 || (!visited[match2[b1]]&&dfs(match2[b1]))){
      match1[a1]=b1;
      match2[b1]=a1;
      return true;
    }
  return false;
}
int main(){
  int tc;
  scanf("%d", &tc);
  while(tc--){
    int N, M, ans=0;
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
      adj[i].clear();
      int a, b;
      scanf("%d %d", &a, &b);
      for(int j=a-1; j<b; j++) adj[i].push_back(j);
    }
    memset(match1, -1, sizeof(match1));
    memset(match2, -1, sizeof(match2));
    for(int i=0; i<M; i++)
      if(match1[i]==-1){
        memset(visited, 0, sizeof(visited));
        if(dfs(i)) ans++;
      }
    printf("%d\n", ans);
  }
}

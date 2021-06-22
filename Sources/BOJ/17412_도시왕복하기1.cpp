//모든 간선의 용량을 1로 두고 최대유량을 구한다
//용량이 1이므로 서로 다른 두 경로의 길은 절대 공유되지 않는다
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX_V=400, SRC=0, SNK=1;
int main()
{
  int N, P;
  //c[u][v]=u에서 v로 보낼 수 있는 용량
  //f[u][v]=u에서 v로 흐르는 유량. 반대방향은 음수
  int c[MAX_V][MAX_V]={0}, f[MAX_V][MAX_V]={0};
  vector<int> adj[MAX_V];
  scanf("%d %d", &N, &P);
  for(int i=0; i<P; i++){
    int u, v;
    scanf("%d %d", &u, &v); u--; v--;
    c[u][v]=1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  //에드몬드-카프 알고리즘
  //증가경로가 더 없을 때까지 너비우선탐색을 통해
  //증가경로를 찾고 경로를 따라 유량을 보낸다
  int totalFlow=0;
  while(1){
    //너비우선탐색으로 증가경로 찾기
    queue<int> Q;
    int parent[MAX_V];
    memset(parent, -1, sizeof(parent));
    Q.push(SRC);
    while(!Q.empty() && parent[SNK]==-1){
      int curr = Q.front(); Q.pop();
      //잔여용량이 남은 간선을 따라 증가경로를 찾는다
      for(int next : adj[curr])
        if(c[curr][next]-f[curr][next]>0 && parent[next]==-1){
          parent[next]=curr;
          if(next==SNK) break;
          Q.push(next);
        }
    }
    //증가경로가 더 이상 없는 경우 종료
    if(parent[SNK]==-1) break;
    //증가경로에 포함된 간선에 유량을 보낸다
    for(int p=SNK; p!=SRC; p=parent[p]){
      f[parent[p]][p]++;
      f[p][parent[p]]--;
    }
    totalFlow++;
  }
  printf("%d\n", totalFlow);
}

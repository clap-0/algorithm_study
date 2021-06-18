#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
//가능한 최대의 정점 수. (MAX_N + MAX_M + 소스 + 싱크)
const int MAX_V=402;
int main()
{
  int N, M, V;
  //capacity[i][j] = i에서 j로 보낼 수 있는 용량
  //flow[i][j] = i에서 j로 흐르는 유량. 반대방향은 음수로 표현
  int capacity[MAX_V][MAX_V]={0}, flow[MAX_V][MAX_V]={0};
  vector<int> adj[MAX_V];
  scanf("%d %d", &N, &M);
  //소스는 0, 싱크는 1
  V=2+N+M;
  for(int i=0; i<N; i++){
    //소스에서 각 소로 가는 간선
    capacity[0][2+i]=1;
    adj[0].push_back(2+i);
    adj[2+i].push_back(0);
    //각 소에서 원하는 축사로 가는 간선
    int S;
    scanf("%d", &S);
    for(int j=0; j<S; j++){
      int shed;
      scanf("%d", &shed); shed--;
      capacity[2+i][2+N+shed]=1;
      adj[2+i].push_back(2+N+shed);
      adj[2+N+shed].push_back(2+i);
    }
  }
  //각 축사에서 싱크로 가는 간선
  for(int i=0; i<M; i++){
    capacity[2+N+i][1]=1;
    adj[2+N+i].push_back(1);
    adj[1].push_back(2+N+i);
  }
  //에드몬드-카프 알고리즘
  int ans=0;
  while(1){
    //너비우선탐색으로 증가경로 탐색
    queue<int> Q;
    int parent[MAX_V];
    memset(parent, -1, sizeof(parent));
    Q.push(0);
    while(!Q.empty()&&parent[1]==-1){
      int curr = Q.front(); Q.pop();
      //잔여용량이 남은 간선을 따라 증가경로 탐색
      for(int next : adj[curr])
        if(capacity[curr][next]-flow[curr][next]>0 && parent[next]==-1){
          Q.push(next);
          parent[next]=curr;
          if(next==1) break;
        }
    }
    //증가경로가 없는 경우 종료
    if(parent[1]==-1) break;
    //증가경로에 포함된 모든 간선에 유량 1 
    for(int p=1; p!=0; p=parent[p]){
      flow[parent[p]][p]++;
      flow[p][parent[p]]--;
    }
    ans++;
  }
  printf("%d\n", ans);
}

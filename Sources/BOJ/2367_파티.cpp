#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N=200, MAX_V=302, SRC=0, SNK=1;

struct Edge{
  int target, c, f;
  Edge* reverse;
  Edge():Edge(-1,0){}
  Edge(int _target, int _c) : target(_target), c(_c), f(0), reverse(0){}
  int r() {return c-f;}
  void push(int a){
    f+=a;
    reverse->f-=a;
  }
};

int main()
{
  int N, K, D;
  vector<Edge*> adj[MAX_V];
  scanf("%d %d %d", &N, &K, &D);
  //음식과 싱크를 잇는 간선 생성
  //각 음식 양의 제한을 용량으로 한다
  for(int i=0; i<D; i++){
    int dish;
    scanf("%d", &dish);
    Edge *e1=new Edge(SNK,dish), *e2=new Edge(2+MAX_N+i,0);
    e1->reverse=e2, e2->reverse=e1;
    adj[2+MAX_N+i].push_back(e1);
    adj[SNK].push_back(e2);
  }
  //소스와 각 사람을 용량이 K인 간선으로 연결하고
  //각 사람과 그 사람이 할 줄 아는 요리를 용량이 1인 간선으로 연결한다
  for(int i=0; i<N; i++){
    Edge *e1, *e2;
    e1=new Edge(2+i,K), e2=new Edge(SRC,0);
    e1->reverse=e2, e2->reverse=e1;
    adj[SRC].push_back(e1);
    adj[2+i].push_back(e2);
    int Z;
    scanf("%d", &Z);
    while(Z--){
      int v;
      scanf("%d", &v); v--;
      e1=new Edge(2+MAX_N+v,1), e2=new Edge(2+i,0);
      e1->reverse=e2, e2->reverse=e1;
      adj[2+i].push_back(e1);
      adj[2+MAX_N+v].push_back(e2);
    }
  }
  //에드몬드-카프 알고리즘
  int totalFlow=0;
  while(1){
    //너비우선탐색으로 증가 경로를 찾는다
    queue<int> Q;
    int parent[MAX_V];
    memset(parent, -1, sizeof(parent));
    Edge* path[MAX_V];
    Q.push(SRC);
    while(!Q.empty() && parent[SNK]==-1){
      int curr = Q.front(); Q.pop();
      //잔여 용량이 남은 간선을 따라 경로를 찾는다
      for(Edge* e : adj[curr]){
        int next = e->target;
        if(e->r()>0 && parent[next]==-1){
          parent[next]=curr;
          path[next]=e;
          if(next==SNK) break;
          Q.push(next);
        }
      }
    }
    //증가 경로가 더 이상 없는 경우 종료
    if(parent[SNK]==-1) break;
    //증가 경로에 포함된 간선을 따라 유량을 보낸다
    for(int p=SNK; p!=SRC; p=parent[p]) path[p]->push(1);
    totalFlow++;
  }
  printf("%d\n", totalFlow);
}

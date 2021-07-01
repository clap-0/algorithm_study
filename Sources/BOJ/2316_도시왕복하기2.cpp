//소스와 싱크를 제외한 모든 정점을
//간선이 들어오는 정점과 나가는 정점으로 쪼개고
//모든 간선의 용량을 1로 두어 한 번 방문한 정점은 두 번 이상 방문하지 못하게 한다
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX_N=400, SRC=0, SNK=1;
//간선의 정보를 나타내는 구조체
struct Edge{
  int target, c, f;
  Edge* reverse;
  Edge():Edge(-1, 0){}
  Edge(int _target, int _c) : target(_target), c(_c), f(0), reverse(nullptr){}
  //잔여 용량 계산
  int r(){return c-f;}
  //이 간선을 따라 a만큼의 유량을 보낸다
  void push(int a){
    f+=a;
    reverse->f-=a;
  }
};
int main()
{
  int N, P;
  //인접리스트를 이용한 유량 네트워크 저장
  vector<Edge*> adj[MAX_N*2];
  scanf("%d %d", &N, &P);
  //소스와 싱크를 제외한 정점을 두 개로 쪼개어
  //쪼개진 두 정점을 용량이 1인 간선으로 잇는다
  for(int i=2; i<N; i++){
    Edge *e1=new Edge(i+MAX_N, 1), *e2=new Edge(i, 0);
    e1->reverse=e2; e2->reverse=e1;
    adj[i].push_back(e1); adj[i+MAX_N].push_back(e2);
  }
  //두 정점 u와 v가 주어졌을 때
  //u의 나가는 정점에서 v의 들어오는 정점으로의 간선과, 그 역방향간선.
  //v의 나가는 정점에서 u의 들어오는 정점으로의 간선과, 그 역방향간선을 추가한다
  for(int i=0; i<P; i++){
    //u1, v1은 들어오는 정점, u2, v2는 나가는 정점
    int u1, v1, u2, v2;
    scanf("%d %d", &u1, &v1); u1--; v1--;
    //소스와 싱크를 제외한 모든 정점을 쪼갠다
    u2=(u1!=SRC&&u1!=SNK ? u1+MAX_N : u1);
    v2=(v1!=SRC&&v1!=SNK ? v1+MAX_N : v1);
    Edge *u2v1=new Edge(v1,1), *v1u2=new Edge(u2,0);
    Edge *v2u1=new Edge(u1,1), *u1v2=new Edge(v2,0);
    u2v1->reverse=v1u2, v1u2->reverse=u2v1;
    v2u1->reverse=u1v2, u1v2->reverse=v2u1;
    adj[u2].push_back(u2v1), adj[v1].push_back(v1u2);
    adj[v2].push_back(v2u1), adj[u1].push_back(u1v2);
  }
  //에드몬드-카프 알고리즘
  int totalFlow=0;
  while(1){
    //너비우선탐색으로 증가 경로 탐색
    queue<int> Q;
    int parent[MAX_N*2];
    memset(parent, -1, sizeof(parent));
    //path[i] = 탐색 중 방문한 i번 정점으로 가는 간선 저장
    Edge* path[MAX_N*2]={0};
    Q.push(SRC);
    parent[SRC]=SRC;
    while(!Q.empty() && parent[SNK]==-1){
      int curr = Q.front(); Q.pop();
      //잔여용량이 남은 간선을 따라 증가 경로 찾음
      for(Edge* next : adj[curr])
        if(next->r()>0 && parent[next->target]==-1){
          parent[next->target]=curr;
          path[next->target] = next;
          if(next->target == SNK) break;
          Q.push(next->target);
        }
    }
    //증가 경로가 더 이상 없으면 종료
    if(parent[SNK]==-1) break;
    //증가 경로에 포함된 간선을 따라 유량을 보낸다
    for(int p=SNK; p!=SRC; p=parent[p]) path[p]->push(1);
    totalFlow++;
  }
  printf("%d\n", totalFlow);
}

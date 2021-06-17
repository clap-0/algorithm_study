#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAX=52, INF=987654321, SINK='Z'-'A';

int main()
{
  int N;
  //capacity[i][j] = i에서 j로 가는 파이프의 용량
  //flow[i][j] = i에서 j로 가는 파이프의 유량
  int capacity[MAX][MAX]={0}, flow[MAX][MAX]={0};
  //파이프의 정보 입력받기
  //노드 이름이 'A'~'Z'면 번호는 0~25, 'a'~'z'면 26~51
  scanf("%d", &N);
  for(int i=0; i<N; i++){
    char a, b;
    int c;
    scanf(" %c %c %d", &a, &b, &c);
    a -= ('A'<=a&&a<='Z' ? 'A' : 'a'-26);
    b -= ('A'<=b&&b<='Z' ? 'A' : 'a'-26);
    capacity[a][b] += c;
    capacity[b][a] += c;
  }
  //에드몬드-카프 알고리즘
  int ans=0;
  while(1){
    queue<int> Q;
    int parent[MAX];
    memset(parent, -1, sizeof(parent));
    Q.push(0);
    parent[0]=0;
    while(!Q.empty() && parent[SINK]==-1){
      int curr = Q.front(); Q.pop();
      //잔여용량이 존재하는 간선을 따라 증가경로를 탐색한다
      for(int i=0; i<MAX; i++)
        if(capacity[curr][i]-flow[curr][i]>0 && parent[i]==-1){
          parent[i]=curr;
          Q.push(i);
        }
    }
    //증가경로가 존재하지 않은 경우 종료
    if(parent[SINK]==-1) break;
    //증가경로에 포함된 간선들 중 잔여용량의 최소값을 찾아
    //유량을 얼마나 보낼지 정한다.
    int amount=INF;
    for(int i=SINK; i!=0; i=parent[i])
      amount=min(amount, capacity[parent[i]][i]-flow[parent[i]][i]);
    //증가경로를 따라 유량을 보낸다
    for(int i=SINK; i!=0; i=parent[i]){
      flow[parent[i]][i]+=amount;
      flow[i][parent[i]]-=amount;
    }
    ans+=amount;
  }
  printf("%d\n", ans);
}

#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N=50, MAX_M=251;
const int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};

int uf[MAX_M];

//간선정보저장
struct Edge{
  int u, v, w;
  Edge():Edge(-1,-1,0){}
  Edge(int _u, int _v, int _w):u(_u),v(_v),w(_w){}
  bool operator<(const Edge&o){return w<o.w;}
};

//n이 속한 트리의 루트번호 반환
int find(int n){
  if(uf[n]<0) return n;
  return uf[n]=find(uf[n]);
}
//u가 속한 트리와 v가 속한 트리 합치기
//이미 같은 트리에 속하면 false 반환
bool merge(int u, int v){
  u=find(u), v=find(v);
  if(u==v) return false;
  uf[v]=u;
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M, vCnt=0, eCnt=0;
  //로봇과 열쇠의 위치를 key로 정점번호를 value로 저장
  map<int,int> vertex;
  char adj[MAX_N][MAX_N];
  cin >> N >> M;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
      cin >> adj[i][j];
      if(adj[i][j]=='S'||adj[i][j]=='K') vertex[i*MAX_N+j]=vCnt++;
    }
  //너비우선탐색을 통해 모든 정점들 사이의 거리를 구하고
  //Edge 구조체를 통해 간선 정보를 저장한다
  Edge e[MAX_M*(MAX_M-1)/2];
  //두 정점을 연결하는 간선의 존재여부
  bool connected[MAX_M][MAX_M]={false};
  //너비우선탐색을 정점의 개수(vCnt)만큼 수행한다
  for(auto &iter : vertex){
    int src=iter.first, u=iter.second, cost=0;
    bool discovered[MAX_N][MAX_N]={false};
    queue<int> Q;
    Q.push(src);
    discovered[src/MAX_N][src%MAX_N]=true;
    connected[u][u]=true;
    while(!Q.empty()){
      int qsize = Q.size();
      for(int i=0; i<qsize; i++){
        int y=Q.front()/MAX_N, x=Q.front()%MAX_N;
        Q.pop();
        //정점 u에서 시작하여 다른 정점을 찾은 경우
        //간선으로 연결되지 않았으면 간선정보를 저장한다
        if(adj[y][x]=='K'){
          int v = vertex[y*MAX_N+x];
          if(!connected[u][v]){
            connected[u][v] = connected[v][u] = true;
            e[eCnt++] = Edge(u, v, cost);
          }
        }
        //상하좌우로 인접한 방문하지 않은 칸을 방문할 목록에 넣는다
        for(int i=0; i<4; i++){
          int ny=y+dy[i], nx=x+dx[i];
          if(ny<0||nx<0||ny>=N||nx>=N) continue;
          if(!discovered[ny][nx] && adj[ny][nx]!='1'){
            discovered[ny][nx]=true;
            Q.push(ny*MAX_N+nx);
          }
        }
      }
      cost++;
    }
  }
  //모든 정점사이에 간선이 만들어지지 않은 경우
  //모든 열쇠를 찾는 것이 불가능하므로 -1 출력 후 종료
  if(eCnt!=vCnt*(vCnt-1)/2){
    puts("-1");
    return 0;
  }
  //크루스칼 알고리즘
  int cnt=0, ans=0;
  sort(e, e+eCnt);
  fill(uf, uf+vCnt, -1);
  for(int i=0;;i++)
    if(merge(e[i].u, e[i].v)){
      ans+=e[i].w;
      if(++cnt==M) break;
    }
  cout << ans << '\n';
}

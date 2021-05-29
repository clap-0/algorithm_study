#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int,int> P;
const int MAX=50, INF=987654321;
const int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};

int n, m, blank;
int adj[MAX][MAX];
vector<int> virusPos; //바이러스의 위치

//활성화된 바이러스의 위치가 주어졌을 때
//모든 칸에 바이러스가 퍼지는데 걸리는 시간 반환(불가능하면 INF반환)
int bfs(vector<int>& activated){
  int ret=0, remaining=blank; //남아있는 빈 칸의 수
  priority_queue<P, vector<P>, greater<P> > pq; //복제시킬 바이러스의 위치 목록
  int discovered[MAX][MAX]; //각 칸에 바이러스가 퍼진데 걸린 시간
  memset(discovered, -1, sizeof(discovered));
  //활성화된 바이러스들부터 복제시킨다
  for(int pos : activated){
    discovered[pos/MAX][pos%MAX]=0;
    pq.push(P(0,pos));
  }
  while(!pq.empty()){
    if(remaining==0) return ret; //더 이상 빈칸이 없으면 걸린 시간 반환
    int time=pq.top().first, curr=pq.top().second;
    pq.pop();
    for(int i=0; i<4; i++){
      int ny=curr/MAX+dy[i], nx=curr%MAX+dx[i];
      if(ny<0||nx<0||ny>=n||nx>=n) continue; //연구소 범위보다 밖인 경우 패스
      if(discovered[ny][nx]!=-1 || adj[ny][nx]==1) continue; //이미 바이러스가 있거나 벽인 경우 패스
      discovered[ny][nx]=time+1;
      pq.push(P(discovered[ny][nx], ny*MAX+nx));
      //빈칸이었던 경우 바이러스가 퍼진데에 걸린시간 계산
      if(adj[ny][nx]==0){
        ret=max(ret, discovered[ny][nx]);
        remaining--;
      }
    }
  }
  return INF;
}

//m개의 바이러스를 활성화시키는 모든 경우에서 걸리는 시간 중 최소시간 반환
int activateVirus(vector<int>& activated, int prev=-1){
  if(activated.size()==m) return bfs(activated);
  int ret=INF;
  for(int i=prev+1; i<virusPos.size(); i++){
    activated.push_back(virusPos[i]);
    ret=min(ret, activateVirus(activated, i));
    activated.pop_back();
  }
  return ret;
}

int main()
{
  cin >> n >> m;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
      cin >> adj[i][j];
      if(adj[i][j]==0) blank++;
      else if(adj[i][j]==2) virusPos.push_back(i*MAX+j);
    }
  vector<int> activated;
  int ans = activateVirus(activated);
  cout << (ans!=INF ? ans : -1) << '\n'; //INF면 -1출력
}

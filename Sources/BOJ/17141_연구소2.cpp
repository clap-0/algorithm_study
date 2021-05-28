#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX=50, INF=987654321;
int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};

int n, m, blank;
int adj[MAX][MAX];
vector<int> virusPos; //바이러스를 놓을 수 있는 칸의 위치 저장

//너비우선탐색을 통해 placed위치에 바이러스를 놓았을 때
//모든 칸에 바이러스가 퍼지는 시간 구함
int bfs(vector<int>& placed){
  int ret=0, remaining=blank+virusPos.size(); //남아있는 바이러스가 안 퍼진 공간의 수
  queue<int> q;
  int time[MAX][MAX]; //각 칸에 바이러스가 퍼진 데 걸린 시간
  memset(time, -1, sizeof(time));
  //placed위치에 바이러스 설치
  for(int pos : placed){
    q.push(pos);
    time[pos/100][pos%100]=0;
    remaining--;
  }
  while(!q.empty()){
    int curr=q.front(); q.pop();
    for(int i=0; i<4; i++){
      int ny=curr/100+dy[i], nx=curr%100+dx[i];
      if(ny<0||nx<0||ny>=n||nx>=n) continue; //연구소 범위 밖인 경우 패스
      if(time[ny][nx]!=-1 || adj[ny][nx]==1) continue; //이미 바이러스가 퍼졌거나 벽이 있는 곳이면 패스
      q.push(ny*100+nx);
      time[ny][nx]=time[curr/100][curr%100]+1;
      ret=max(ret, time[ny][nx]); //바이러스가 퍼지는데 걸린 시간 계산
      remaining--;
    }
  }
  if(remaining!=0) return INF; //모든 칸에 바이러스가 퍼지지 못한 경우 INF반환
  return ret;
}

//완전탐색을 통해 바이러스 m개를 놓는 가능한 모든 경우를 시도하고
//이 중 모든 빈칸에 바이러스를 퍼뜨리는 최소 시간을 반환
int placeVirus(vector<int>& placed, int prev=-1){
  if(placed.size()==m) return bfs(placed); //바이러스 m개를 전부 놓으면 바이러스를 퍼뜨리고 걸린시간 반환
  int ret=INF;
  for(int i=prev+1; i<virusPos.size(); i++){
    placed.push_back(virusPos[i]);
    ret=min(ret, placeVirus(placed, i));
    placed.pop_back();
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
      else if(adj[i][j]==2) virusPos.push_back(i*100+j);
    }
  vector<int> placed;
  int ans = placeVirus(placed);
  cout << (ans!=INF ? ans : -1) << '\n'; //INF인 경우 -1 출력
}

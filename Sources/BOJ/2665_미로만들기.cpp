#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX=50, INF=987654321;
const int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};

char adj[MAX][MAX];
bool discovered[MAX][MAX];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> adj[i][j];
  //다익스트라(?) 알고리즘
  //인접한 방을 방문할 때 바꿔야하는 방의 수는 어차피 0이나 1이므로
  //시작방에서 각 방까지 가는데 바꿔야 하는 방의 수 대신
  //너비우선탐색처럼 각 방의 방문여부를 저장
  priority_queue<pair<int,int> > pq;
  pq.push({0,0});
  discovered[0][0]=true;
  while(!pq.empty()){
    int cost=-pq.top().first;
    int here=pq.top().second;
    pq.pop();
    for(int i=0; i<4; i++){
      int ny=here/MAX+dy[i], nx=here%MAX+dx[i];
      if(ny<0||nx<0||ny>=n||nx>=n) continue;
      //시작방에서 이 방에 갈 때까지 바꾸는 방의 수
      int nextCost=cost+(adj[ny][nx]=='1' ? 0 : 1);
      //끝방에 도착한 경우
      if(ny==n-1 && nx==n-1){
        cout << nextCost << '\n';
        return 0;
      }
      //처음 발견한 방에 한해 방문한다
      if(!discovered[ny][nx]){
        pq.push({-nextCost, ny*MAX+nx});
        discovered[ny][nx]=true;
      }
    }
  }
}

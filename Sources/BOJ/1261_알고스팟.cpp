#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int m, n;
int dy[4]={-1, 0, 0, 1}, dx[4]={0, -1, 1, 0};
vector<string> adj; //인접행렬
int dijkstra(void){ //(0,0)에서 (n-1,m-1)까지 갈 때 부숴야하는 최소한의 벽 개수 반환
  vector<vector<int> > toBreak(n, vector<int>(m, -1));
  toBreak[0][0] = 0;
  priority_queue<pair<int, pair<int, int> > > pq;
  pq.push({0, {0, 0}});
  while(!pq.empty()){
    int broken = -pq.top().first;
    int y = pq.top().second.first, x = pq.top().second.second;
    pq.pop();
    if(y==n-1&&x==m-1) return broken; //(n-1, m-1)도착 시 지금까지 부순 벽 개수 반환
    for(int i=0; i<4; i++){ //상하좌우 확인
      int ny = y+dy[i], nx = x+dx[i];
      if(ny==-1||nx==-1||ny==n||nx==m) continue; //범위밖이면 패스
      if(toBreak[ny][nx]!=-1) continue; //이미 확인했으면 패스
      int nextBroken = broken+adj[ny][nx]-'0';
      toBreak[ny][nx] = nextBroken;
      pq.push({-nextBroken, {ny, nx}});
    }
  }
  return toBreak[n-1][m-1];
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> m >> n;
  adj.resize(n);
  for(int i=0; i<n; i++)
    cin >> adj[i];
  cout << dijkstra() << endl;
  return 0;
}

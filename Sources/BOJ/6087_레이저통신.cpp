#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

// 다익스트라 알고리즘을 이용하여 startPoint[0]에서 startPoint[1]로 레이저를 연결하는 데에 필요한 거울의 최소 개수를 구한다
int getMinMirror(vector<int>& startPoint, vector<vector<bool> >& map) {
  int W = map[0].size(), H = map.size();
  int S = startPoint[0], E = startPoint[1];
  
  // mirror[] : S에서 해당 좌표까지 레이저로 연결하는 데에 필요한 거울의 최소 개수. 큰 수(10000)으로 초기화한다
  vector<int> mirror(H * 100 + W, 10000);
  // 우선순위큐에 { 필요한 거울개수, {현 좌표, 이동방향} }을 저장한다
  priority_queue<pair<int, pair<int,int> > > pq;
  
  mirror[S] = 0;
  for(int i = 0; i < 4; i++) pq.push({0, {S, i}});
  
  while(!pq.empty()) {
    int currMirror = -pq.top().first, pos = pq.top().second.first, dir = pq.top().second.second;
    pq.pop();
    
    // 현재 좌표까지 오는 데에 사용한 거울 개수보다 더 적게 사용하여 현 좌표를 방문한 적이 있는 경우 건너뛰기
    // 사용한 거울 개수가 같은 경우 이동방향의 차이가 있을 수 있으므로 건너뛰지 않는다
    if(mirror[pos] < currMirror) continue;
    
    // 이동하던 방향을 기준으로 레이저를 좌회전, 직진, 우회전시키는 경우를 구한다
    int y = pos / 100, x = pos % 100, d = (dir + 3) % 4;
    for(int i = 0; i < 3; i++, d = (d + 1) % 4) {
      int ny = y + dy[d], nx = x + dx[d];
      
      // 해당 칸이 지도 밖이거나 벽인 경우 건너뛴다
      if(ny < 0 || nx < 0 || ny >= H || nx >= W || map[ny][nx]) continue;
      
      // 방향 d로 이동할 때 필요한 거울의 수가 기존에 구한 방법보다 적은 경우 큐에 넣는다
      // 필요한 거울의 수가 같은 경우도 이동방향의 차이를 고려하여 큐에 넣는다
      int nextPos = ny * 100 + nx, nextMirror = currMirror + (d != dir);
      if(mirror[nextPos] >= nextMirror) {
        mirror[nextPos] = nextMirror;
        pq.push({-nextMirror, {nextPos, d}});
      }
    }
  }
  return mirror[E];
}

int main()
{
  int W, H;
  scanf("%d %d", &W, &H);
  
  // map[][] : 지도상에서 빈 칸(.)과 레이저로 연결해야 하는 칸(C)은 0으로, 벽(*)은 1로 저장한다 
  vector<vector<bool> > map(H, vector<bool>(W, false));
  // startPoint : 레이저로 연결해야 하는 칸(C)의 좌표를 저장한다
  vector<int> startPoint;
  
  char ch;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      scanf(" %c", &ch);
      if(ch == '*') map[i][j] = true;
      else if(ch == 'C') startPoint.push_back(i*100 + j);
    }
  }
  
  printf("%d\n", getMinMirror(startPoint, map));
}

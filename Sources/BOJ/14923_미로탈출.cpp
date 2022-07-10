#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int N, M;
bool maze[1000][1000];
// bfsDist[i][j] = 시작점에서 i행j열까지의 최단거리 정보
// rbfsDist[i][j] = 도착점에서 i행j열까지의 최단거리 정보
int bfsDist[1000][1000], rbfsDist[1000][1000];

// 너비우선탐색을 통해 Hx행 Hy열에서 도달가능한 각 방까지의 최단거리를 dist에 저장하는 함수
void bfs(int Hx, int Hy, int Ex, int Ey, int dist[][1000])
{
  queue<pair<int,int> > Q;
  Q.push({Hx, Hy});
  dist[Hx][Hy] = 0;
  int distance = 1;
  while(!Q.empty())
  {
    int qSize = Q.size();
    while(qSize--)
    {
      int x = Q.front().first, y = Q.front().second;
      Q.pop();

      for(int i = 0; i < 4; i++)
      {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M || dist[nx][ny] != -1) continue;
        // 벽을 만나면 더 나아갈 수 없으므로 큐에 넣지 않는다.
        if(!maze[nx][ny])
          Q.push({nx, ny});
        // 벽 한 칸까지의 최단거리는 저장한다.
        dist[nx][ny] = distance;
      }
    }
    ++distance;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int Hx, Hy, Ex, Ey;
  cin >> N >> M >> Hx >> Hy >> Ex >> Ey;
  --Hx, --Hy, --Ex, --Ey;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      cin >> maze[i][j];
  
  memset(bfsDist, -1, sizeof(bfsDist));
  memset(rbfsDist, -1, sizeof(rbfsDist));
  bfs(Hx, Hy, Ex, Ey, bfsDist);
  bfs(Ex, Ey, Hx, Hy, rbfsDist);

  // bfsDist[i][j] + rbfsDist[i][j]의 최솟값을 구한다
  int ans = 987654321;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      if(bfsDist[i][j] != -1 && rbfsDist[i][j] != -1)
        ans = min(ans, bfsDist[i][j] + rbfsDist[i][j]);
  
  cout << (ans != 987654321 ? ans : -1) << '\n';
}

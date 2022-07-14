#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

int R, C;
bool visited[1000][1000]; // 지훈이의 각 공간의 방문여부 저장
bool isBlocked[1000][1000]; // 각 공간에 벽이나 불이 있으면 true, 아니면 false.

// 넓이우선탐색을 이용하여 start 위치에서 미로를 탈출하는 데에 걸리는 시간을 반환한다.
// 미로에서 빠져나가는 방법이 없는 경우 -1을 반환한다.
int bfs(pair<int,int>& start, queue<pair<int,int> > fires)
{
  queue<pair<int,int> > Q;
  Q.push(start);
  visited[start.first][start.second] = true;

  int ret = 1;
  while(!Q.empty())
  {
    // 불을 먼저 네 방향으로 확산시킨다.
    int fireSize = fires.size();
    while(fireSize--)
    {
      int y = fires.front().first, x = fires.front().second;
      fires.pop();
      for(int i = 0; i < 4; i++)
      {
        int ny = y + dy[i], nx = x + dx[i];
        // 미로의 바깥이나 벽 너머로 불은 확산하지 못한다.
        if(ny < 0 || nx < 0 || ny >= R || nx >= C || isBlocked[ny][nx])
          continue;
        fires.push({ny, nx});
        isBlocked[ny][nx] = true;
      }
    }

    int qSize = Q.size();
    while(qSize--)
    {
      int y = Q.front().first, x = Q.front().second;
      Q.pop();

      for(int i = 0; i < 4; i++)
      {
        int ny = y + dy[i], nx = x + dx[i];
        // 미로의 바깥에 도착한 경우 걸린 시간을 반환한다.
        if(ny < 0 || nx < 0 || ny >= R || nx >= C)
          return ret;
        // 장애물이 없고, 아직 방문하지 않는 공간인 경우 방문한다.
        if(!isBlocked[ny][nx] && !visited[ny][nx])
        {
          Q.push({ny, nx});
          visited[ny][nx] = true;
        }
      }
    }
    ++ret;
  }
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  queue<pair<int,int> > fires;
  pair<int,int> start;
  cin >> R >> C;
  for(int i = 0; i < R; i++)
    for(int j = 0; j < C; j++)
    {
      char ch;
      cin >> ch;
      switch (ch)
      {
        case 'F':
          fires.push({i, j});
        case '#':
          isBlocked[i][j] = true;
          break;
        case 'J':
          start = {i, j};
          break;
        default:
          break;
      }
    }
  
  int ans = bfs(start, fires);
  if(ans != -1)
    cout << ans << '\n';
  else
    cout << "IMPOSSIBLE\n";
}

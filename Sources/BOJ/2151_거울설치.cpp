#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[4] = {-1,0,1,0}, dx[4] = {0,-1,0,1};

vector<int> doors;
char house[50][50];
int visited[50][50][4];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> house[i][j];
      if (house[i][j] == '#')
        doors.push_back(i * 50 + j);
    }

  int ans = 987654321;
  queue<pair<int, pair<int,int> > > Q;
  fill((int*)visited, (int*)(visited + 50), 987654321);
  
  // 첫 번째 문에서 상하좌우로 바라보는 경우
  for (int i = 0; i < 4; i++) {
    Q.push({0, {doors[0], i}});
    visited[doors[0] / 50][doors[0] % 50][i] = 0;
  }
  
  // BFS
  while (!Q.empty()) {
    int cnt = Q.front().first;
    int pos = Q.front().second.first, dir = Q.front().second.second;
    Q.pop();
    
    // 두 번째 문에 도달한 경우
    if (pos == doors[1]) {
      ans = min(ans, cnt);
      continue;
    }
    
    int y = pos / 50, x = pos % 50;
    // 직진
    int ny = y + dy[dir], nx = x + dx[dir];
    if (!(ny < 0 || nx < 0 || ny >= N || nx >= N || house[ny][nx] == '*') && visited[ny][nx][dir] > cnt) {
      Q.push({cnt, {ny * 50 + nx, dir}});
      visited[ny][nx][dir] = cnt;
    }
    
    // 현 위치에 거울을 설치 가능하는 경우
    if (house[y][x] == '!') {
      // 진행방향의 왼쪽으로
      ny = y + dy[(dir + 1) % 4], nx = x + dx[(dir + 1) % 4];
      if (!(ny < 0 || nx < 0 || ny >= N || nx >= N || house[ny][nx] == '*') && visited[ny][nx][(dir + 1) % 4] > cnt + 1) {
        Q.push({cnt + 1, {ny * 50 + nx, (dir + 1) % 4}});
        visited[ny][nx][(dir + 1) % 4] = cnt + 1;
      }
      // 진행방향의 오른쪽으로
      ny = y + dy[(dir + 3) % 4], nx = x + dx[(dir + 3) % 4];
      if (!(ny < 0 || nx < 0 || ny >= N || nx >= N || house[ny][nx] == '*') && visited[ny][nx][(dir + 3) % 4] > cnt + 1) {
        Q.push({cnt + 1, {ny * 50 + nx, (dir + 3) % 4}});
        visited[ny][nx][(dir + 3) % 4] = cnt + 1;
      }
    }
  }

  cout << ans << '\n';
}

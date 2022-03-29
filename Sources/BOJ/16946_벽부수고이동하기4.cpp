#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

int wall[1000][1000]; // wall[i][j] = i행 j열이 벽이면 양수값, 빈 칸이면 0

// uf[n] = (n / 1000)행 (n % 1000)열이 빈 칸인 경우 해당 위치에서 이동가능한 칸들로 이루어진 트리의 루트 번호를 가진다
// 만약 해당 위치가 루트이면 트리에 속한 정점들의 개수의 음수값을 가진다
// 해당 위치가 벽인 경우 0이다
int uf[1000000];

// n이 속한 트리의 루트번호를 반환한다
int find(int n) {
  if(uf[n] < 0) return n;
  return uf[n] = find(uf[n]);
}

// v가 속한 트리를 u가 속한 트리의 자식이 되도록 합친다
void merge(int u, int v) {
  u = find(u), v = find(v);
  if(u == v) return;
  uf[u] += uf[v];
  uf[v] = u;
}

int main()
{
  int N, M;

  // 입력
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) {
      scanf("%1d", &wall[i][j]);
      if(!wall[i][j]) uf[i * 1000 + j] = -1;  // 빈 칸인 경우 -1을 가진다
    }

  // 인접한 빈 칸들을 유니온파인드 알고리즘을 이용해 집합으로 합친다
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      if(!wall[i][j]) {
        if(i + 1 < N && !wall[i + 1][j])
          merge(i * 1000 + j, (i + 1) * 1000 + j);
        if(j + 1 < M && !wall[i][j + 1])
          merge(i * 1000 + j, i * 1000 + j + 1);
      }

  // 출력
  for(int y = 0; y < N; y++) {
    for(int x = 0; x < M; x++) {
      if(!wall[y][x]) printf("0");  // 빈 칸인 경우 "0"출력
      // 벽이 있는 공간인 경우
      else {
        int reachable = 1;  // 벽이 있던 위치를 부쉈으므로 이동가능한 칸이 최소 하나 존재
        vector<int> visited;  // visited : 인접한 칸 중 방문했던 칸의 번호를 저장

        // 상하좌우에서 방문한 적 없는 빈 칸을 찾아 해당 빈 칸에서 이동가능한 칸의 개수를 reachable에 더한다
        for(int i = 0; i < 4; i++) {
          int ny = y + dy[i], nx = x + dx[i];
          if(ny < 0 || nx < 0 || ny >= N || nx >= M || wall[ny][nx]) continue;  // 맵의 바깥이거나 벽인 경우 이동불가

          int cell = find(ny * 1000 + nx);  // cell : [ny][nx]칸이 속한 트리의 루트번호
          if(std::find(visited.begin(), visited.end(), cell) != visited.end()) continue;  // [ny][nx]칸에서 이동가능한 칸을 이미 방문했던 경우 넘긴다

          visited.push_back(cell);
          reachable += -uf[cell];
        }
        printf("%d", reachable % 10);
      }
    }
    printf("\n");
  }
}

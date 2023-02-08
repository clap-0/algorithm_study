#include <iostream>
#include <queue>
using namespace std;

int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};
int S[1000][1000];
bool visited[1000][1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(); cout.tie();

  int N, M, K;
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> S[i][j];

  int ans = 0, cnt = 0;
  // 강도가 가장 작은 광물이 우선순위가 높도록 하기 위해
  // 우선순위 큐에 강도를 음수로 바꾸어 넣었다.
  priority_queue<pair<int,pair<int,int> > > pq;
  
  // 공기와 맞닿아있는 광물들을 우선순위큐에 넣는다.
  for (int i = 0; i < M; i++) {
    pq.push({-S[0][i], {0, i}});
    visited[0][i] = true;
  }
  if (N > 1) {
    for (int i = 1; i < N; i++) {
      pq.push({-S[i][0], {i, 0}});
      visited[i][0] = true;
    }
    if (M > 1)
      for (int i = 1; i < N; i++) {
        pq.push({-S[i][M - 1], {i, M - 1}});
        visited[i][M - 1] = true;
      }
  }
  
  while (!pq.empty()) {
    int strength = -pq.top().first;
    int r = pq.top().second.first, c = pq.top().second.second;
    pq.pop();

    ans = max(ans, strength); // 현재까지 채굴한 광물들 중 가장 강도가 높은 것이 정답이다.
    if (++cnt == K) break;  // 광물을 K번 채굴하면 종료

    // 채굴한 광물에 인접한 광물들을 우선순위 큐에 삽입
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i], nc = c + dc[i];
      if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc]) continue;
      pq.push({-S[nr][nc], {nr, nc}});
      visited[nr][nc] = true;
    }
  }
  cout << ans << '\n';
}

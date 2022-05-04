#include <iostream>
#include <cmath>
using namespace std;

int N;
double cost[16][16];
double cache[16][1 << 16];

// 현재 도시 current와 방문했던 도시들을 비트마스킹으로 표현한 visited가 주어졌을 때
// DP를 이용하여 가장 적은 순회 비용을 반환한다
double TSP(int current, int visited) {
  // 모든 도시를 방문한 경우, 마지막 도시에서 시작도시로 가는 비용을 반환한다
  if(visited + 1 == 1 << N) return cost[current][0];

  // 메모이제이션
  double& ret = cache[current][visited];
  if(ret != 0) return ret;

  // 아직 방문하지 않은 도시들을 방문하며 최소 비용을 구한다
  ret = 1e9;
  for(int i = 0; i < N; i++)
    if(!(visited & (1 << i)))
      ret = min(ret, cost[current][i] + TSP(i, visited | (1 << i)));

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  pair<int,int> pos[16];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> pos[i].first >> pos[i].second;

  // 각 도시의 위치를 바탕으로 한 도시에서 다른 도시로 가는 비용을 구한다
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++) {
      int dx = pos[i].first - pos[j].first, dy = pos[i].second - pos[j].second;
      cost[i][j] = sqrt(dx * dx + dy * dy);
    }

  cout << fixed;
  cout.precision(6);
  cout << TSP(0, 1) << '\n';
}

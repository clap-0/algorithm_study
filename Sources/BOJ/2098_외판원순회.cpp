#include <iostream>
#include <cstring>
using namespace std;

int N;
int cost[16][16];
int cache[16][1<<16];
const int START = 0;

// 비트필드를 이용한 다이나믹 프로그래밍
// 현재 위치 curr와 각 도시의 방문여부를 비트마스킹으로 표현한 visited를 매개변수로 받아 최소 순회비용을 구한다
int TSP(int curr, int visited) {
  // 메모이제이션
  int& ret = cache[curr][visited];
  if(ret != -1) return ret;

  // 모든 도시를 다 방문한 경우, 마지막 도시에서 시작 도시로 가는 비용을 반환한다.
  // 마지막 도시에서 시작 도시로 가는 길이 없는 경우 큰 수를 반환한다.
  if(visited + 1 == (1 << N))
    return ret = (cost[curr][START] ? cost[curr][START] : 1e9);
  
  // 방문하지 않았고 curr에서 가는 길이 있는 도시를 방문했을 때 비용의 최솟값을 구한다.
  ret = 1e9;
  for(int i = 0; i < N; i++)
    if(!(visited & (1 << i)) && cost[curr][i])
      ret = min(ret, cost[curr][i] + TSP(i, visited | (1 << i)));

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      cin >> cost[i][j];
  
  memset(cache, -1, sizeof(cache));
  cout << TSP(START, 1 << START) << '\n';
}

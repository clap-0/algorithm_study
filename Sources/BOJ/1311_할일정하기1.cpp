#include <iostream>
#include <algorithm>
using namespace std;

int N;
int costs[20][20];
int cache[20][1 << 20];

// 비트필드를 이용한 DP를 사용해서 N명의 사람이 모두 일을 하는데 필요한 비용의 최솟값을 구한다
int getMinCost(int person, int completedWorks) {
  // N명의 사람에 대해 모두 탐색을 했으면 0 반환
  if(person == N) return 0;

  // 메모이제이션
  int& ret = cache[person][completedWorks];
  if(ret) return ret;

  // 아직 완료되지 않은 일들에 대해서 person번째 사람이 수행하고,
  // (person + 1)번째 사람에 대해 탐색하는 것을 재귀적으로 반복한다
  ret = 987654321;
  for(int i = 0; i < N; i++)
    if(!(completedWorks & (1 << i))) {
      ret = min(ret, costs[person][i] + getMinCost(person + 1, completedWorks | (1 << i)));
    }
  
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      cin >> costs[i][j];

  cout << getMinCost(0, 0) << '\n';
}

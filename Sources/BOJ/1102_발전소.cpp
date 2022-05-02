#include <iostream>
#include <cstring>
using namespace std;

const int INF = 987654321;
int N, P;
int cost[16][16];
int cache[1 << 16];

// 각 발전소의 작동 여부를 비트마스킹을 이용하여 isWorking으로 주어질 때
// 해당 작동 상태에서 P개 이상의 발전소를 가동하는 데 필요한 최소 비용을 반환한다
int getMinRepairCost(int isWorking) {
  // P개 이상의 발전기가 작동되는 경우 0 반환
  if(__builtin_popcount(isWorking) >= P) return 0;

  // 메모이제이션
  int& ret = cache[isWorking];
  if(ret != -1) return ret;

  ret = INF;
  // 가동되지 않은 발전기를 찾아서 해당 발전기를 가동시킨 후
  // P개 이상의 발전기를 가동시키는데 필요한 최소비용을 nextCost에 저장한다
  for(int j = 0; j < N; j++)
    if(!(isWorking & (1 << j))) {
      int nextCost = getMinRepairCost(isWorking | (1 << j));
      // 앞서 새로 가동시킨 발전기를 가동시키는 데에 필요한 최소비용을
      // nextCost와 더한 값이 최소가 되도록 한다
      for(int i = 0; i < N; i++)
        if(isWorking & (1 << i)) {
          ret = min(ret, cost[i][j] + nextCost);
        }
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
      cin >> cost[i][j];

  char ch;
  int isWorking = 0;
  for(int i = 0; i < N; i++) {
    cin >> ch;
    if(ch == 'Y') isWorking |= (1 << i);
  }

  cin >> P;

  // P개의 발전기를 가동시키지 못하는 상황이면 -1 출력
  if(isWorking == 0 && P > 0) cout << -1 << '\n';
  else {
    memset(cache, -1, sizeof(cache));
    cout << getMinRepairCost(isWorking) << '\n';
  }
}

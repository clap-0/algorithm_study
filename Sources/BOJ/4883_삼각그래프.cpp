#include <iostream>
#include <vector>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int tc = 0;
  while (true)
  {
    int N;
    cin >> N;
    if (N == 0)
      break;
    
    vector<int> cache(3), cost(3);
    cin >> cache[0] >> cache[1] >> cache[2];
    // 가장 위쪽 가운데에서 오른쪽으로 가는 경우
    cache[2] += cache[1];
    // 가장 위의 왼쪽에서는 출발 불가
    cache[0] = 987654321;
    for (int i = 1; i < N; i++)
    {
      cin >> cost[0] >> cost[1] >> cost[2];
      cost[0] += min(cache[0], cache[1]);
      cost[1] += min(cost[0], min(cache[0], min(cache[1], cache[2])));
      cost[2] += min(cost[1], min(cache[1], cache[2]));
      cache = cost;
    }
    cout << ++tc << ". " << cache[1] << '\n';
  }
}

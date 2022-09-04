#include <iostream>
#include <algorithm>
using namespace std;

int candies[100000];
long long psum[100001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int M, N;
  cin >> M >> N;
  for (int i = 0; i < N; i++)
    cin >> candies[i];
  // 친구들이 받고 싶어한 사탕의 개수를 오름차순 정렬
  sort(candies, candies + N);

  // 정렬된 사탕의 개수의 누적합을 구한다.
  for (int i = 0; i < N; i++)
    psum[i + 1] = psum[i] + candies[i];
  
  // ans의 자료형을 unsigned long long으로 하여 자동으로 (1<<64)의 나머지를 구하도록 했다.
  unsigned long long ans = 0ULL;
  int idx = 0;
  while (true) {
    unsigned long long sum = psum[N] - psum[idx]; // candies[idx + 1, N)의 부분합
    int cnt = N - idx;  // 위 부분합에 속한 사탕들의 개수
    // cnt명의 친구들이 동일한 개수의 사탕을 못 받도록 가진 사탕을 전부 주었을 때, 한 사람당 못 받은 사탕의 수
    unsigned long long average = (sum - M) / cnt; 
    // 못 받은 사탕의 수가 원하는 사탕 수가 가장 작은 친구의 사탕 수보다 작거나 같은 경우
    // 친구들이 동일한 개수의 사탕을 못 받도록 하여 분노수치를 구한다.
    if (average <= candies[idx]) {
      int remainder = (sum - M) % cnt;
      ans += average * average * (cnt - remainder);
      // 사탕 개수가 부족한 경우, 부족한 개수만큼의 친구들은 하나를 덜 받도록 해서 구한다.
      ans += (average + 1) * (average + 1) * remainder;
      break;
    }
    else {  // 못 받은 사탕의 수가 원하는 사탕 수가 가장 작은 친구의 사탕 수보다 큰 경우,
      // average보다 작은 수의 사탕을 원하는 친구들에게는 사탕을 주지 않는다.
      int newIdx = lower_bound(candies, candies + N, average) - candies;
      for (; idx < newIdx; ++idx)
        ans += 1ULL * candies[idx] * candies[idx];
    }
  }
  cout << ans << '\n';
}

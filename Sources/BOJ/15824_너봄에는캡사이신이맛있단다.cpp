#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
int scoville[300000];
int cache[300000];

// 분할정복을 이용하여 2^k를 구한다
// 문제해결 도중 pow()를 자주 실행시키기 때문에 시간을 단축시키기 위해 DP도 사용했다
int pow(int k) {
  int& ret = cache[k];
  if(ret != 0) return ret;
  if(k == 0) return ret = 1;
  if(k % 2) return ret = 2 * pow(k - 1) % MOD;
  long long half = pow(k / 2);
  return ret = half * half % MOD;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> scoville[i];

  sort(scoville, scoville + N);

  // 모든 조합에 대하여 (조합의 최댓값 - 조합의 최솟값)의 합을 구해야 하므로
  // 다르게 생각하면 음식의 스코빌지수 수치 scoville에 대하여 ( (scoville이 최댓값이 되는 조합의 수 - scoville이 최솟값이 되는 조합의 수) * (scoville) )의
  // 모든 음식에 대한 합으로 구할 수 있다
  long long ans = 0;
  for(int i = 0; i < N; i++) {
    // pow(i) = i번째 수가 최댓값이 되는 조합의 수, pow(N - 1 - i) = i번째 수가 최솟값이 되는 조합의 수
    long long tmp = (pow(i) - pow(N - 1 - i) + MOD) % MOD;
    tmp = (scoville[i] % MOD * tmp) % MOD;
    ans = (ans + tmp) % MOD;
  }
  cout << ans << '\n';
}

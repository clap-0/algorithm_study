#include <iostream>
#include <vector>
using namespace std;

// 에라토스테네스의 체 알고리즘을 이용하여
// N 이하의 소수들을 반환한다
vector<int> eratosthenes(int N) {
  vector<int> ret;
  vector<bool> isPrime(N + 1, true);
  isPrime[0] = isPrime[1] = false;
  
  // 2를 제외한 짝수는 소수가 아니므로
  // 홀수만을 판별하도록 반복문을 돌린다
  if(N >= 2) ret.push_back(2);
  for(int i = 3; i <= N; i += 2)
    if(isPrime[i]) {
      ret.push_back(i);
      for(long long j = 1LL * i * i; j <= N; j += i * 2) isPrime[j] = false;
    }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  
  // N이 1인 경우 N이하의 소수가 없다
  if(N == 1) {
    cout << 0 << '\n';
    return 0;
  }

  vector<int> primes = eratosthenes(N);
  
  // 두 포인터 알고리즘을 이용하여
  // [lo, hi] 범위의 연속된 구간의 합 sum이 N인 구간의 개수를 구한다
  int lo = primes.size() - 1, hi = lo, sum = primes.back(); // lo와 hi를 N 이하의 가장 큰 소수로 초기화한다
  int ans = 0;
  while(true) {
    if(sum == N) ++ans;
    
    if(sum <= N && lo > 0) sum += primes[--lo]; // sum이 N보다 작거나 같으면 sum에 (lo - 1)번째 소수값을 더한다
    else if(hi > 0) sum -= primes[hi--];        // sum이 N보다 크면 sum에 hi번째 소수값을 뺀다
    else break; // lo == 0 && hi == 0 이면 반복문을 종료한다
  }

  cout << ans << '\n';
}

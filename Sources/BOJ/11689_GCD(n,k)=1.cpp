#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// MAX_P = n의 최댓값(1e12)의 제곱근
const int MAX_P = 1e6;
vector<int> primes;

// 에라토스테네스의 체 알고리즘을 이용하여
// MAX_P 미만의 소수들을 구한다
void eratosthenes() {
  vector<bool> isPrime(MAX_P, true);
  isPrime[0] = isPrime[1] = false;
  primes.push_back(2);
  
  // 2를 제외한 짝수는 모두 합성수이므로 (i += 2)로 홀수만을 판별했다
  for(int i = 3; i < MAX_P; i += 2)
    if(isPrime[i]) {
      for(long long j = 1LL * i * i; j < MAX_P; j += i * 2) 
        isPrime[j] = false;
      primes.push_back(i);
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  long long n;
  cin >> n;

  eratosthenes();
  
  // 오일러 파이 함수 φ(a)의 계산 (자세한 내용은 구글링)
  // 1. φ(m)φ(n)=φ(m*n)(단, m,n은 서로소)
  // 2. φ(pᵏ)=pᵏ-pᵏ⁻¹ (p는 소수)
  // 3. φ(a)=a*(1-1/p₁)*(1-1/p₂)*...*(1-1/pₙ)
  long long ans = n, tmp = n;
  for(int p : primes)
    if(tmp % p == 0) {
      ans /= p;
      ans *= (p - 1);
      while(tmp % p == 0) tmp /= p;
    }

  // n의 소수인 소인수가 n의 제곱근보다 큰 경우
  if(tmp > 1) {
    ans /= tmp;
    ans *= (tmp - 1);
  }

  cout << ans << '\n';
}

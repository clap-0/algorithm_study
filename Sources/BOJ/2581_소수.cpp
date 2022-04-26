#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> primes;

// 에라토스테네스의 체 알고리즘
void eratosthenes(int N) {
  if(N == 1) return;
  vector<bool> isPrime(N + 1, true);
  primes.push_back(2);
  for(int i = 3; i <= N; i += 2) 
    if(isPrime[i]) {
      primes.push_back(i);
      for(int j = i * i; j <= N; j += 2 * i)
        isPrime[j] = false;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int M, N;
  cin >> M >> N;

  eratosthenes(N);
  vector<int>::iterator iter = lower_bound(primes.begin(), primes.end(), M);

  if(iter == primes.end()) cout << -1 << '\n';
  else {
    int minimum = *iter;
    int sum = 0;
    while(iter != primes.end()) sum += *iter++;
    cout << sum << '\n' << minimum << '\n';
  }
}

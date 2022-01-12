#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N = 100000, MAX_P = 1299709;

int prime[MAX_N];
bool isPrime[MAX_P+1];

// 에라토스테네스의 체 알고리즘
void eratosthenes() {
  memset(isPrime, 1, sizeof(isPrime));
  isPrime[0] = isPrime[1] = false;
  
  int sqrtn = int(sqrt(MAX_P));
  for(int i=2; i<=sqrtn; i++)
    if(isPrime[i])
      for(int j=i*i; j<=MAX_P; j+=i)
        isPrime[j] = false;
  
  // i가 소수이면 prime 배열에 추가한다
  for(int i=2, cnt=0; i<=MAX_P; i++)
    if(isPrime[i])
      prime[cnt++]=i;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  eratosthenes();
  
  int T;
  cin >> T;
  while(T--) {
    int k;
    cin >> k;
    
    // k가 소수인 경우 0을 출력한다
    if(isPrime[k])
      cout << 0 << '\n';
    // prime 배열에서 k보다 큰 가장 작은 수와 k보다 작은 가장 큰 수의 차를 구한다
    else {
      int p = *(upper_bound(prime, prime+MAX_N, k) - 1);
      int n = *upper_bound(prime, prime+MAX_N, k) - p;
      cout << n << '\n';
    }
  }
}

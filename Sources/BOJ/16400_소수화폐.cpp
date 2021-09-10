#include <iostream>
#include <vector>
using namespace std;
vector<int> primeNumbers;
int dp[40001];
//에라토스테네스의 체 알고리즘
void eratosthenes(int n){
  vector<bool> isPrime(n+1, true);
  for(int i=2; i<=n; i++)
    if(isPrime[i]){
      for(int j=i*i; j<=n; j+=i) isPrime[j]=false;
      primeNumbers.push_back(i);
    }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  eratosthenes(N);
  //반복적동적계획법
  dp[0]=1;
  //N보다 작거나 같은 소수들을 이용하여
  //숫자 n을 어떤 소수보다 작거나 같은 소수들의 합으로 만드는 방법의 개수를 반복적으로 구한다
  for(int prime : primeNumbers)
    for(int n=prime; n<=N; n++) dp[n]=(dp[n]+dp[n-prime])%123456789;
  cout << dp[N] << '\n';
}

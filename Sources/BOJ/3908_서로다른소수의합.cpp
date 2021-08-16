#include <iostream>
#include <vector>
using namespace std;
const int MAX_N=1120, MAX_K=14;
//MAX_N 이하의 소수들
vector<int> primes;
//dp[i][j] = 값 i를 j개의 서로 다른 소수를 이용하여 만들 수 있는 경우의 수
int dp[MAX_N+1][MAX_K+1];

//에라토스테네스의 체를 이용하여 MAX_N 이하의 소수들을 구한다
void findPrimeNum(){
  vector<bool> isPrime(MAX_N+1, true);
  for(int i=2; i<=MAX_N; i++)
    if(isPrime[i]){
      primes.push_back(i);
      for(int j=i*i; j<=MAX_N; j+=i) isPrime[j]=false;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  findPrimeNum();
  int psize=primes.size();
  //반복적 동적계획법
  //primes[]의 p번 이하 인덱스의 값들만을 이용하도록 순서를 강제하여
  //덧셈의 순서만 다른 경우가 생기지 않도록 한다
  dp[0][0]=1;
  for(int p=0; p<psize; p++)
    for(int n=MAX_N; n>=primes[p]; n--)
      for(int k=1; k<=MAX_K; k++)
        dp[n][k]+=dp[n-primes[p]][k-1];
  int T;
  cin >> T;
  while(T--){
    int N, K;
    cin >> N >> K;
    cout << dp[N][K] << '\n';
  }
}

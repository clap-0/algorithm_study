#include <iostream>
#include <vector>
using namespace std;
const int MAX_N=1000000, SQRTN=1000;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  //에라토스테네스의 체
  vector<bool> isPrime(MAX_N+1, true);
  isPrime[0]=isPrime[1]=false;
  for(int i=2; i<=SQRTN; i++)
    if(isPrime[i])
      for(int j=i*i; j<=MAX_N; j+=i)
        isPrime[j]=false;
  //주어진 짝수 n에 대해 골드바흐의 추측이 맞는지 확인
  while(1){
    int n;
    cin >> n;
    if(n==0) break;
    bool ok=false;
    int iter;
    for(iter=3; iter<=n/2; iter+=2){
      if(isPrime[iter]&&isPrime[n-iter]){
        ok=true;
        break;
      }
    }
    if(ok) cout << n << " = " << iter << " + " << n-iter << '\n';
    else cout << "Goldbach's conjecture is wrong." << '\n';
  }
  return 0;
}

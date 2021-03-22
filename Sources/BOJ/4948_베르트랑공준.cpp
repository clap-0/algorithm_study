#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX=246912;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  //범위 내 모든 수에 대해 에라토스테네스의 체
  vector<bool> isPrime(MAX+1, true);
  isPrime[0]=isPrime[1]=false;
  int sqrtn = int(sqrt(MAX));
  for(int i=2; i<=sqrtn; i++)
    if(isPrime[i])
      for(int j=i*i; j<=MAX; j+=i)
        isPrime[j]=false;
  while(1){
    int n, ret=0;
    cin >> n;
    if(n==0) break;
    for(int i=2*n; i>n; i--)
      ret+=isPrime[i];
    cout << ret << endl;
  }
  return 0;
}

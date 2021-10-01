#include <iostream>
#include <cstring>
using namespace std;
int P, Q;
long long dp[10001];
// 피보나치 수
long long fib(int n){
  if(dp[n]!=-1) return dp[n];
  long long a = fib(n/2);
  if(n%2){
    long long b = fib(n/2+1);
    return dp[n] = (a*a%Q + b*b%Q) % Q;
  }
  else {
    long long b = fib(n/2-1);
    return dp[n] = (a*a%Q + 2*a%Q*b%Q) % Q;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  for(int tc=1; tc<=T; tc++){
    cin >> P >> Q;
    memset(dp, -1, sizeof(dp));
    dp[1] = dp[2] = 1%Q;
    cout << "Case #" << tc << ": " << fib(P)%Q << '\n';
  }
}

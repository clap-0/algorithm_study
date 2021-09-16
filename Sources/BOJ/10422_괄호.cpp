#include <iostream>
using namespace std;
long long dp[5001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T, L;
  cin >> T;
  // 반복적동적계획법
  dp[0]=dp[2]=1;
  for(int l=4; l<=5000; l+=2)
    for(int i=2; i<=l; i+=2)
      dp[l]=(dp[l]+(dp[i-2]*dp[l-i])%1000000007)%1000000007;
  while(T--){
    cin >> L;
    cout << dp[L] << '\n';
  }
}

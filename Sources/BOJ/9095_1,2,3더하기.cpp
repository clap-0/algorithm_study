#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    int dp[11];
    cin >> n;
    dp[1]=1, dp[2]=2, dp[3]=4;
    for(int i=4; i<=n; i++) //Bottom-up
      dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    cout << dp[n] << endl;
  }
  return 0;
}

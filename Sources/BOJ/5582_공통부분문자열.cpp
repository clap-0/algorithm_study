#include <iostream>
using namespace std;
string A, B;
int dp[4001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> A >> B;
  int aLen=A.length(), bLen=B.length(), ans=0;
  // 반복적동적계획법을 통해 A[..a-1]과 B[..b-1]의 가장 긴 공통부분문자열을 구한다
  for(int a=1; a<=aLen; a++)
    for(int b=bLen; b>=1; b--){
      dp[b] = (A[a-1]!=B[b-1] ? 0 : dp[b-1]+1);
      ans=max(ans, dp[b]);
    }
  cout << ans << '\n';
}

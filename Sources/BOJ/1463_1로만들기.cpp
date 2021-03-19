#include <iostream>
using namespace std;
int dp[1000001];
int main()
{
  int n;
  cin >> n;
  dp[2]=1, dp[3]=1;
  for(int i=4; i<=n; i++){ //Bottom-up
    dp[i]=dp[i-1]+1; //3번 연산
    if(!(i%3)) dp[i]=min(dp[i], dp[i/3]+1); //1번 연산
    if(!(i%2)) dp[i]=min(dp[i], dp[i/2]+1); //2번 연산
  }
  cout << dp[n] << endl;
  return 0;
}

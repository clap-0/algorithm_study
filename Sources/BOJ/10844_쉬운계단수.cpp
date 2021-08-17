#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, ans=0;
  int dp[101][10]={0};
  cin >> N;
  //반복적 동적계획법
  for(int i=1; i<10; i++) dp[1][i]=1;
  for(int pos=2; pos<=N; pos++)
    for(int num=0; num<10; num++){
      if(num>0) dp[pos][num]=(dp[pos][num]+dp[pos-1][num-1])%1000000000;
      if(num<9) dp[pos][num]=(dp[pos][num]+dp[pos-1][num+1])%1000000000;
    }
  for(int i=0; i<10; i++) ans=(ans+dp[N][i])%1000000000;
  cout << ans << '\n';
}

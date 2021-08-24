//순서에 상관없이 중복을 포함하여 K개의 정수로 N을 만드는 것이므로
//중복조합을 이용하여 kHn을 구한다
#include <iostream>
using namespace std;
int dp[10000];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, K;
  cin >> N >> K;
  //1C0 = 1C1 = 1
  dp[0]=dp[1]=1;
  for(int n=2; n<=N+K-1; n++){
    //nCn = 1
    dp[n]=1;
    //파스칼의 삼각형을 이용하여 nCr을 구한다
    //이때 r을 큰 수부터 구하므로 dp[n][r]이 아닌 dp[r]을 이용해 저장해도 무방하다
    for(int r=n-1; r>0; r--)
      dp[r]=(dp[r-1]+dp[r])%1000000000;
  }
  //kHn = k+n-1Cn
  cout << dp[N] << '\n';
}

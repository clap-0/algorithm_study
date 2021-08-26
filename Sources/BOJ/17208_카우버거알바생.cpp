#include <iostream>
using namespace std;
int dp[301][301];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, M, K;
  cin >> N >> M >> K;
  //DP를 이용하여 배낭문제 풀기
  for(int n=0; n<N; n++){
    int x, y;
    cin >> x >> y;
    for(int m=M; m>=x; m--)
      for(int k=K; k>=y; k--) dp[m][k]=max(dp[m][k], 1+dp[m-x][k-y]);
  }
  cout << dp[M][K] << '\n';
}

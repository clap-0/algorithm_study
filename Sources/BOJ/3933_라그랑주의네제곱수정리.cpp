#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 1 << 15;

int dp[MAX_N][4]; // dp[i][k] = i를 (k+1)개의 제곱수의 합으로 만드는 방법의 수

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  
  for(int j = 1; j * j <= MAX_N; j++) {
    ++dp[j * j][0];
    for(int i = j * j; i < MAX_N; i++)
      for(int k = 1; k < 4; k++)
        dp[i][k] += dp[i - j * j][k - 1];
  }
  
  int n;
  while(true) {
    cin >> n;
    if(n == 0) return 0;
    cout << dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] << '\n';
  }
}

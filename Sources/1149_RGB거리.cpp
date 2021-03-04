#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int dp[1000][3];
  for(int i=0; i<n; i++)
    cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
  for(int i=1; i<n; i++){ //Bottom-up
    for(int j=0; j<3; j++){
      dp[i][j] += min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
    }
  }
  cout << min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << endl;
  return 0;
}

#include <iostream>
using namespace std;

const int INF = 10000;
int dp[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    dp[i] = INF;
  }
  dp[0] = 0;
  
  for (int i = 0; i < N; i++) {
    int jump;
    cin >> jump;
    for (int j = 1; j <= jump && i + j < N; j++) {
      dp[i + j] = min(dp[i + j], 1 + dp[i]);
    }
  }

  cout << (dp[N - 1] != INF ? dp[N - 1] : -1) << '\n';
}

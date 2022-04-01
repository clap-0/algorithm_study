#include <iostream>
using namespace std;

int vol[50];
bool dp[51][1001];

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, S, M;
  cin >> N >> S >> M;
  for(int i = 0; i < N; i++) cin >> vol[i];

  
  // 다이나믹 프로그래밍
  dp[0][S] = true;
  for(int i = 0; i < N; i++)
    for(int j = 0; j <= M; j++)
      if(dp[i][j]) {  // i번째 곡을 연주할 때 볼륨이 j였다면 (i + 1)번째 곡의 볼륨은 (j ± vol[i])이다
        if(j + vol[i] <= M) dp[i + 1][j + vol[i]] = true;
        if(j - vol[i] >= 0) dp[i + 1][j - vol[i]] = true;
      }

  // 곡을 모두 연주했을 때의 볼륨 중 가장 큰 값을 ans에 저장한다
  int ans = -1;
  for(int i = M; i >= 0; i--)
    if(dp[N][i]) {
      ans = i;
      break;
    }

  cout << ans << '\n';
}

#include <iostream>
using namespace std;

int L[20], J[20];
int dp[100];  // dp[i] = 체력이 i일 때 얻을 수 있는 최대 기쁨

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> L[i];
  for(int i = 0; i < N; i++) cin >> J[i];

  // DP를 이용한 배낭문제 풀기
  for(int i = 0; i < N; i++) 
    for(int j = 99; j >= L[i]; j--) // i번 사람에게 여러번 말하는 것을 막기 위해 역순
      dp[j] = max(dp[j], J[i] + dp[j - L[i]]);
  
  cout << dp[99] << '\n';
}

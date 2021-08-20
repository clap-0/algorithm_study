#include <iostream>
using namespace std;
int N, K;
int dp[501][501];
pair<int,int> checkpoint[501];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> K;
  for(int i=1; i<=N; i++) cin >> checkpoint[i].first >> checkpoint[i].second;
  //반복적 동적계획법
  for(int to=2; to<=N; to++){
    //to번 체크포인트까지 최대 K번 건너뛸 때 각각의 횟수에 대해 큰 수로 초기화한다
    for(int chances=0; chances<=K; chances++) dp[to][chances]=987654321;
    for(int from=1; from<to; from++){
      //jump: from에서 to로 건너뛸 때 건너뛰는 체크포인트의 수
      int jump=to-from-1;
      for(int chances=K; chances>=jump; chances--)
        dp[to][chances-jump]=min(dp[to][chances-jump], dp[from][chances]+abs(checkpoint[from].first-checkpoint[to].first)+abs(checkpoint[from].second-checkpoint[to].second));
    }
  }
  cout << dp[N][0] << '\n';
}

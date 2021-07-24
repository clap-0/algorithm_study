#include <iostream>
#include <cstring>
using namespace std;
int N, cars;
int psum[50001], carried[50000];
int dp[3][50001], maxDp[3][50001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  //psum[i] = 1번부터 i번 객차까지의 타고있던 손님 수의 합
  for(int i=1; i<=N; i++){
    int passengers;
    cin >> passengers;
    psum[i]=psum[i-1]+passengers;
  }
  cin >> cars;
  //각 연결된 객차를 끌 때 운송하는 손님 수
  for(int i=0; i+cars<=N; i++) carried[i]=psum[i+cars]-psum[i];
  //반복적동적계획법
  int cnt=N-cars*2-1;
  for(int train=0; train<3; train++)
    for(int i=0; i<cnt; i++){
      int start=i+cars*train+1;
      if(train>0) dp[train][start] = maxDp[train-1][start-cars];
      dp[train][start] += carried[start-1];
      maxDp[train][start]=max(dp[train][start], maxDp[train][start-1]);
    }
  int ans=0;
  for(int i=1; i<=cnt; i++) ans=max(ans, dp[2][cars*2+i]);
  cout << ans << '\n';
}

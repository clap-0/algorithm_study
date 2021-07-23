#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //dp[i] = i번 작업까지 완료하는데 걸리는 최소시간
  int N, cost[10000], dp[10000], endTime=0;
  cin >> N;
  //반복적동적계획법을 이용하여 작업 완료에 필요한 최소시간 구하기
  //어떤 작업까지 완료하는데 걸리는 시간은
  //이 작업의 선행작업들 중 가장 마지막에 완료된 작업의 완료시간 + 이 작업에 걸리는 시간이다 
  for(int i=0; i<N; i++){
    int j;
    cin >> cost[i] >> j;
    dp[i]=0;
    //해당 작업의 선행작업들 중 가장 오래 걸린 작업을 구한다
    while(j--){
      int prev;
      cin >> prev;
      dp[i]=max(dp[i], dp[prev-1]);
    }
    //i번 작업을 하는데 걸리는 시간을 더한다
    dp[i]+=cost[i];
    //모든 작업이 끝나는데 걸리는 시간을 구한다
    endTime=max(endTime, dp[i]);
  }
  cout << endTime << '\n';
}

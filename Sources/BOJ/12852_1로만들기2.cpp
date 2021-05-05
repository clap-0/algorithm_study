#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000001;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  int dp[MAX], next[MAX]; //next[i] = i에 3개중 최적의 연산을 했을 때의 값
  cin >> n;
  
  next[2] = next[3] = dp[2] = dp[3] = 1;
  next[1] = dp[1] = 0;
  
  for(int i=4; i<=n; i++){
    //3번연산 (1을 뺀다)
    dp[i] = dp[i-1]+1;
    next[i] = i-1;
    //1번연산 (3으로 나누어 떨어지면, 3으로 나눈다)
    if(!(i%3) && dp[i]>dp[i/3]+1){ //3번연산 했을 때보다 연산을 더 적게 쓸 수 있는 경우
      dp[i] = dp[i/3]+1;
      next[i] = i/3;
    }
    //2번연산 (2로 나누어 떨어지면, 2로 나눈다)
    if(!(i%2) && dp[i]>dp[i/2]+1){ //3,1번연산 했을 때보다 연산을 더 적게 쓸 수 있는 경우
      dp[i] = dp[i/2]+1;
      next[i] = i/2;
    }
  }
  
  cout << dp[n] << '\n';
  int k = n;
  while(k!=0){
    cout << k << ' ';
    k = next[k];
  }
}

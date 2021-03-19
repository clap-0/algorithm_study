#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int dp[100001];
  for(int i=1; i<=n; i++){ //i를 1의 제곱수의 합으로 나타낼 때 항의 수로 초기화 
    dp[i]=i;
  }
  for(int i=4; i<=n; i++){
    for(int j=2; j*j<=i; j++){
      dp[i] = min(dp[i], dp[i-j*j]+1); //i를 i보다 작은 제곱수로 뺀 수의 항의 최솟값 +1 의 최솟값 구하기 
    }
  }
  cout << dp[n] << endl;
  return 0;
}

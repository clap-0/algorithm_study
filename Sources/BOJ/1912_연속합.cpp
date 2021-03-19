#include <iostream>
#include <vector>
using namespace std;
vector<int> vec(100000);
int main()
{
  int n, maxSum;
  cin >> n;
  for(int i=0; i<n; i++) cin >> vec[i];
  int dp[100001]; //dp[i] = i번째 수를 포함하는 i까지의 연속합의 최댓값
  maxSum = dp[0] = vec[0];
  for(int i=1; i<n; i++){ //Bottom-up
    dp[i]=max(0, dp[i-1])+vec[i]; //i-1에서의 연속합의 최댓값+i번째 수 or i번째 수
    maxSum=max(maxSum, dp[i]);
  }
  cout << maxSum << endl;
  return 0;
}

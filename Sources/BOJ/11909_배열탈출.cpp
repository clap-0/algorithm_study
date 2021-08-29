#include <iostream>
using namespace std;
int arr[2222][2222], dp[2222][2222];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
      dp[i][j]=1e9;
    }
  //반복적동적계획법
  dp[0][0]=0;
  //i행 j열로 가는데 눌러야 하는 최소 버튼의 수는
  //i-1행 j열과 i행 j-1열에서 (누른 최소버튼+해당칸에서 올 때 눌러야하는 버튼 수) 중 더 작은 값이 된다
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++){
      if(i!=0) dp[i][j]=min(dp[i][j], dp[i-1][j]+max(arr[i][j]+1-arr[i-1][j], 0));
      if(j!=0) dp[i][j]=min(dp[i][j], dp[i][j-1]+max(arr[i][j]+1-arr[i][j-1], 0));
    }
  cout << dp[n-1][n-1] << '\n';
}

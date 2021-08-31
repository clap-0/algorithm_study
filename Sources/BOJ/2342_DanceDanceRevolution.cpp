#include <iostream>
#include <algorithm>
using namespace std;
int dp[2][5][5];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int step, cnt=0;
  //반복적동적계획법
  //첫번째 발판은 무조건 오른발로 밟도록 강제한다(왼발로 밟아도 좌우만 바뀔뿐 결과는 같으므로)
  cin >> step;
  fill(dp[0][0], dp[0][5], 1000000000);
  dp[0][step][0]=2;
  while(1){
    cin >> step;
    if(step==0) break;
    ++cnt;
    //cnt번째때 발 위치가 될 수 없는 것들은 모두 1e9로 초기화한다
    fill(dp[cnt%2][0], dp[cnt%2][5], 1000000000);
    for(int l=0; l<5; l++)
      for(int r=0; r<5; r++)
        //이전 차례에 (l,r)에 발을 놓았던 경우
        if(dp[(cnt-1)%2][l][r]!=1000000000){
          //이번 차례에 밟을 발판에 이미 발이 올라가 있는 경우 이전 차례까지 사용한 힘+1
          if(step==l||step==r) dp[cnt%2][l][r]=min(dp[cnt%2][l][r],dp[(cnt-1)%2][l][r]+1);
          else {
            //왼발을 step발판으로 움직이는 경우
            if(l==0) dp[cnt%2][step][r]=min(dp[cnt%2][step][r], dp[(cnt-1)%2][l][r]+2);
            else dp[cnt%2][step][r]=min(dp[cnt%2][step][r], dp[(cnt-1)%2][l][r]+(abs(step-l)%2==1?3:4));
            //오른발을 step발판으로 움직이는 경우
            if(r==0) dp[cnt%2][l][step]=min(dp[cnt%2][l][step], dp[(cnt-1)%2][l][r]+2);
            else dp[cnt%2][l][step]=min(dp[cnt%2][l][step], dp[(cnt-1)%2][l][r]+(abs(step-r)%2==1?3:4));
          }
        }
  }
  int ans=1000000000;
  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++) ans=min(ans, dp[cnt%2][i][j]);
  cout << ans << '\n';
}

#include <iostream>
#include <cstring>
using namespace std;
const int UP_2=0, DOWN=1, UP=2, DOWN_2=3;
int dp[101][10][4];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  if(N==1){
    cout << 10 << '\n';
    return 0;
  }
  //반복적 동적계획법
  for(int i=0; i<10; i++){
    if(i!=0) dp[2][i][UP]=1;
    if(i!=9) dp[2][i][DOWN]=1;
  }
  for(int pos=3; pos<=N; pos++){
    for(int num=0; num<10; num++){
      for(int i=0; i<4; i++){
        if((num==0&&(i%2==0)) || (num==1&&(i==UP_2)) || (num==8&&(i==DOWN_2)) || (num==9&&(i%2==1))) continue;
        int& curr=dp[pos][num][i];
        switch(i){
          case UP_2: 
          curr=dp[pos-1][num-1][UP];
          break;
          case DOWN:
          curr=(dp[pos-1][num+1][UP]+dp[pos-1][num+1][UP_2])%1000000007;
          break;
          case UP:
          curr=(dp[pos-1][num-1][DOWN]+dp[pos-1][num-1][DOWN_2])%1000000007;
          break;
          case DOWN_2:
          curr=dp[pos-1][num+1][DOWN];
          break;
        }
      }
    }
  }
  int ans=0;
  for(int num=0; num<10; num++)
    for(int i=0; i<4; i++){
      ans+=dp[N][num][i];
      ans%=1000000007;
    }
  cout << ans << '\n';
}

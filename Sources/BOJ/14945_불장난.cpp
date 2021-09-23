#include <iostream>
using namespace std;
int dp[101][101];
int main()
{
  // 반복적 동적계획법
  // row번째 행에서 기웅이와 민수사이의 거리가 dist인 경우의 수를 반복적으로 구한다
  // 이때 계산의 효율성을 위해 기웅이가 민수보다 무조건 왼쪽에 있다고 가정하고 푼 뒤 나온 답에 곱하기 2를 한다
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  // 2번째 행에는 두 칸밖에 없으므로 기웅이와 민수가 다른 타일을 밟는 경우는 하나뿐이다
  dp[2][1]=1;
  for(int row=3; row<=N; row++)
    for(int dist=1; dist<row; dist++){
      // (↓↘), (↓↓,↘↘), (↘↓)
      dp[row][dist]+=(dp[row-1][dist-1] + 2*dp[row-1][dist] + dp[row-1][dist+1]);
      dp[row][dist]%=10007;
    }
  int ans=0;
  for(int dist=1; dist<N; dist++) ans=(ans+dp[N][dist])%10007;
  ans=(ans*2)%10007;
  cout << ans << '\n';
}

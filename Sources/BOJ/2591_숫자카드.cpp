#include <iostream>
using namespace std;
// dp[n] = n번째 수까지의 가능한 배열의 수
int dp[41];
int num[41];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  string card;
  cin >> card;
  int N = card.length();
  // card의 수를 문자에서 정수로 변환하여 저장한다
  for(int i=1; i<=N; i++) num[i] = card[i-1]-'0';
  // 반복적동적계획법
  // 카드가 1~34까지밖에 없는 것과 0이 포함되지 않는 것을 유의한다
  dp[0]=dp[1]=1;
  for(int n=2; n<=N; n++){
    // n에 있는 한자릿수를 분리하는 경우 n-1까지의 가능한 배열의 수와 같다
    if(num[n]!=0) dp[n]=dp[n-1];
    // n-1과 n으로 두자릿수를 분리하는 경우 n-2까지의 가능한 배열의 수와 같다
    if(num[n-1]!=0 && num[n-1]*10+num[n]<=34) dp[n]+=dp[n-2];
  }
  cout << dp[N] << '\n';
}

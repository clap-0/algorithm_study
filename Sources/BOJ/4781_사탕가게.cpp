#include <iostream>
#include <cstring>
using namespace std;
//dp[i]=돈이 i만큼 있을 때 구매할 수 있는 가장 높은 칼로리
int dp[10001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  while(1){
    int N, M;
    double m;
    cin >> N >> m;
    if(N==0&&m==0.00) break;
    //100을 곱해 정수로 만든다. 이때 반올림을 위해 0.5를 더한다
    M=m*100+0.5;
    //반복적 동적계획법
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<N; i++){
      int calory, price;
      double p;
      cin >> calory >> p;
      //정수로 변환
      price=p*100+0.5;
      //돈이 x만큼 있는 경우 얻을 수 있는 가장 높은 칼로리는
      //이전에 나온 물건들 중 돈이 x만큼 있을 때 구매해서 얻은 칼로리의 최댓값 dp[x]와
      //이 물건을 구매해서 얻는 칼로리 calory+dp[x-price] 중 더 큰 값이다
      //이때 중복을 위해 price부터 M순으로 구한다
      for(int j=price; j<=M; j++) dp[j]=max(dp[j], calory+dp[j-price]);
    }
    cout << dp[M] << '\n';
  }
}

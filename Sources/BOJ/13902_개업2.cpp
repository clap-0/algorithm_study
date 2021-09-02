#include <iostream>
#include <algorithm>
using namespace std;
const int INF=987654321;
int wok[1000], dp[10001];
bool canMake[10001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, M;
  cin >> N >> M;
  fill(dp, dp+10001, INF);
  //가지고 있는 웍의 크기가 주어질 때
  //그 웍만 사용하거나 다른 웍들 중 하나와 같이 사용해 요리 한번만에 만들 수 있는 짜장면 그릇 수를 구한다
  for(int i=0; i<M; i++){
    cin >> wok[i];
    dp[wok[i]]=canMake[wok[i]]=1;
    for(int j=0; j<i; j++)
      if(wok[i]+wok[j]<=N) dp[wok[i]+wok[j]]=canMake[wok[i]+wok[j]]=1;
  }
  //반복적동적계획법
  for(int n=1; n<=N; n++){
    //요리 한번으로 짜장면 n그릇을 만들 수 있다면
    if(!canMake[n]) continue;
    //k그릇을 만드는데 필요한 요리 수는 k-n그릇 만드는데 필요한 요리 수+1 (단, k-n그릇을 만드는 방법이 있는경우)
    for(int k=n+1; k<=N; k++)
      if(dp[k-n]!=INF) dp[k]=min(dp[k], dp[k-n]+1); 
  }
  cout << (dp[N]!=INF ? dp[N] : -1) << '\n';
}

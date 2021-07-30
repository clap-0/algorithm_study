#include <iostream>
#include <cstring>
using namespace std;
int N, M;
int amount[20], cache[20][10001];
//DP를 이용하여 coin번째 이상의 동전을 사용하여
//money만큼의 금액을 만드는 방법의 수를 구함
int solve(int coin, int money){
  //기저사례 : 동전들로 money만큼의 금액을 만든 경우
  if(money==0) return 1;
  //메모이제이션
  int& ret = cache[coin][money];
  if(ret!=-1) return ret;
  ret=0;
  for(int i=coin; i<N; i++)
    if(money>=amount[i]) ret += solve(i, money-amount[i]);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while(T--){
    cin >> N;
    for(int i=0; i<N; i++) cin >> amount[i];
    cin >> M;
    memset(cache, -1, sizeof(cache));
    cout << solve(0,M) << '\n';
  }
}

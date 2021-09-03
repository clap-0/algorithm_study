#include <iostream>
#include <cstring>
using namespace std;
int N, M;
//investment[i][j] = 돈이 j만큼 있고, i와 그 이후 기업에만 투자할 때 최대이익을 얻기 위해 i에 투자할 금액
int investment[20][301];
int profit[20][301], cache[20][301];
//DP를 이용하여 돈이 money만큼 있을 때
//m번부터 N-1번까지의 기업에 투자해 얻을 수 있는 최대이익을 구한다
int solve(int m, int money){
  //메모이제이션
  int& ret=cache[m][money];
  if(ret!=-1) return ret;
  //확인할 기업이 하나밖에 없는 경우 그 기업에 남은 돈을 모두 투자한다
  if(m==N-1){
    investment[m][money]=money;
    return ret=profit[m][money];
  }
  //m번 기업에 투자하지 않는 경우
  ret=solve(m+1, money);
  //m번 기업에 투자했을 때 얻는 최대이익을 구하고
  //최대이익일때의 투자금을 구한다
  for(int i=1; i<=money; i++){
    int temp=profit[m][i]+solve(m+1, money-i);
    if(ret<temp){
      ret=temp;
      investment[m][money]=i;
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> M;
  for(int i=0; i<N; i++){
    int amount;
    cin >> amount;
    for(int j=0; j<M; j++) cin >> profit[j][amount];
  }
  memset(cache, -1, sizeof(cache));
  cout << solve(0, N) << '\n';
  for(int i=0, amount=N; i<M; i++){
    cout << investment[i][amount] << ' ';
    amount-=investment[i][amount];
  }
}

#include <cstdio>
using namespace std;
int main()
{
  int N;
  //canWin[i] = 돌이 i개 남았을 때 현재 차례인 사람이 이길 수 있는가
  bool canWin[1001];
  scanf("%d", &N);
  //마지막 돌을 가져가는 사람이 이긴다
  canWin[1]=canWin[3]=canWin[4]=true, canWin[2]=false;
  //Bottom-up 방식의 DP
  //내가 선택을 한 후 다음 차례의 사람이 지는 경우가 하나라도 있으면 이길 수 있다
  for(int i=5; i<=N; i++)
    canWin[i]=!(canWin[i-1]&&canWin[i-3]&&canWin[i-4]);
  printf("%s\n", canWin[N]?"SK":"CY");
}

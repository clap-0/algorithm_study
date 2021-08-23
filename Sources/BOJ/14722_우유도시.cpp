#include <iostream>
#include <cstring>
using namespace std;
int N, milk[1000][1000], cache[1000][1000][3];
//DP를 이용하여 현재 위치 (y,x)와 이전에 마신 우유 prevMilk가 주어질 때
//목적지까지 가는 동안 마실 수 있는 우유의 최대 개수를 구한다
int countMilk(int y, int x, int prevMilk){
  //메모이제이션
  int& ret=cache[y][x][prevMilk];
  if(ret!=-1) return ret;
  //목적지까지 도착한 경우 이 가게의 우유를 마실 수 있으면 1, 없으면 0 반환
  if(y==N-1&&x==N-1) return ret=milk[y][x]==(prevMilk+1)%3;
  ret=0;
  //이 가게의 우유를 마실 수 있는 지 여부
  //마실 수 있는 가게가 있으면 무조건 사 마신다
  bool canDrink=milk[y][x]==(prevMilk+1)%3;
  if(y<N-1) ret=max(ret, canDrink+countMilk(y+1, x, canDrink?milk[y][x]:prevMilk));
  if(x<N-1) ret=max(ret, canDrink+countMilk(y, x+1, canDrink?milk[y][x]:prevMilk));
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++) cin >> milk[i][j];
  memset(cache, -1, sizeof(cache));
  cout << countMilk(0, 0, 2) << '\n';
}

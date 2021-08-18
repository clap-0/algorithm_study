#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int b[3];
int cache[501][501];
//DP를 이용하여 두 통 속에 구슬이 k1, k2개 들어있을 때
//현재 차례인 사람이 이길 수 있는지 구한다
int canWin(int k1, int k2){
  //기저사례: 더이상 꺼낼 구슬이 없는 경우 지게 된다
  if(k1==0&&k2==0) return false;
  //k1이 항상 k2보다 크거나 같게 만든다(중복확인 방지)
  if(k1<k2) swap(k1,k2);
  //메모이제이션
  int& ret=cache[k1][k2];
  if(ret!=-1) return ret;
  ret=false;
  //구슬을 꺼내는 3가지 방법 중 하나라도
  //꺼낸 다음 상대가 지게 된다면 내가 이기는 방법이 있다
  for(int i=0; i<3; i++){
    if(k1>=b[i]) ret |= !canWin(k1-b[i],k2);
    if(k2>=b[i]) ret |= !canWin(k1,k2-b[i]);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> b[0] >> b[1] >> b[2];
  memset(cache, -1, sizeof(cache));
  for(int i=0; i<5; i++){
    int k1, k2;
    cin >> k1 >> k2;
    cout << (canWin(k1,k2) ? 'A' : 'B') << '\n';
  }
}

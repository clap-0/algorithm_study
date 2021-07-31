#include <iostream>
#include <cstring>
using namespace std;
int cache[101][101][2];
//DP를 이용하여 현재 확인하는 비트 curr, 남은 인접한 비트의 개수 cnt, 이전 비트 prevBit가 주어졌을 때
//인접한 비트의 개수가 k인 크기 n의 수열의 개수를 구한다
int adjBit(int curr, int cnt, bool prevBit){
  //기저사례 : 모든 비트를 확인한 경우 만들어진 수열의 인접한 비트의 개수가 k인지 반환
  if(curr==0) return cnt==0;
  //메모이제이션
  int& ret = cache[curr][cnt][prevBit];
  if(ret!=-1) return ret;
  //이 수열의 현재 비트를 0으로 한다
  ret = adjBit(curr-1, cnt, 0);
  //이전 비트가 1이면 현재 비트를 1로 했을 때 cnt가 1 줄어든다
  if(prevBit==0) ret += adjBit(curr-1, cnt, 1);
  else if(cnt>0) ret += adjBit(curr-1, cnt-1, 1);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  memset(cache, -1, sizeof(cache));
  while(T--){
    int n, k;
    cin >> n >> k;
    cout << adjBit(n, k, 0) << '\n';
  }
}

#include <iostream>
#include <cstring>
using namespace std;
int psum[1001];
int cache[1001][1001];
//DP를 이용하여 범위[s,e]내에 있는 카드중에서
//최적의 전략으로 가져갔을 때 얻는 점수를 구한다
int solve(int s, int e){
  //기저사례: 범위내에 카드가 없는 경우 0반환
  if(s>e) return 0;
  //메모이제이션
  int& ret=cache[s][e];
  if(ret!=-1) return ret;
  //가장 왼쪽과 오른쪽 카드 중 가져간 이후 상대가 얻는 점수가 더 적게 되는 것을 가져간다
  int getLeft=solve(s+1, e), getRight=solve(s, e-1);
  return ret=psum[e]-psum[s-1]-min(getLeft, getRight);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    psum[0]=0;
    for(int i=1; i<=N; i++){
      int card;
      cin >> card;
      //부분합 구하기
      psum[i]=psum[i-1]+card;
    }
    memset(cache, -1, sizeof(cache));
    cout << solve(1, N) << '\n';
  }
}

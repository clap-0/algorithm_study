#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int d[3]={1,3,9};
int cache[61][61][61];
//DP를 이용하여 SCV의 남은 체력이 주어질 때 이 SCV들을 모두 파괴하기 위해 필요한 공격횟수의 최솟값을 구한다
int countAttacks(int scv1, int scv2, int scv3){
  //기저사례: 모든 scv가 파괴된 경우 0 반환
  if(scv1+scv2+scv3==0) return 0;
  //메모이제이션
  int& ret=cache[scv1][scv2][scv3];
  if(ret!=-1) return ret;
  ret=100;
  //3개의 scv를 공격하는 순서의 모든 경우의 수에 따라 공격한 후
  //scv를 파괴하기 위한 공격횟수의 최솟값을 구한다
  do {
    ret=min(ret, countAttacks(max(scv1-d[0],0), max(scv2-d[1],0), max(scv3-d[2],0)));
  } while(next_permutation(d, d+3));
  return ++ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  int scv[3]={0};
  cin >> N;
  for(int i=0; i<N; i++) cin >> scv[i];
  memset(cache, -1, sizeof(cache));
  cout << countAttacks(scv[0], scv[1], scv[2]) << '\n';
}

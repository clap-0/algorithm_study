#include <iostream>
#include <cstring>
using namespace std;
int N, K;
int sat[20];
int cache[20][200];
// DP를 이용하여 pos까지의 만족도가 currSat일 때의 최대 탈피에너지 구하기
int getEnergy(int pos, int currSat){
  // 기저사례: 나뭇가지의 끝에 도착한 경우
  if(pos==N) return 0;
  // 메모이제이션
  int& ret=cache[pos][currSat];
  if(ret!=-1) return ret;
  // pos번째 먹이를 포기하는 경우. 만족도가 0이 된다
  ret=getEnergy(pos+1, 0);
  // pos번째 먹이를 먹었을 때 만족도가 최소 만족도 이상이면 탈피에너지로 축적하고 아니면 만족도만 증가시킨다
  if(currSat+sat[pos]>=K) ret=max(ret, getEnergy(pos+1, 0)+currSat+sat[pos]-K);
  else ret=max(ret, getEnergy(pos+1, currSat+sat[pos]));
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> K;
  for(int i=0; i<N; i++) cin >> sat[i];
  memset(cache, -1, sizeof(cache));
  cout << getEnergy(0, 0) << '\n';
}

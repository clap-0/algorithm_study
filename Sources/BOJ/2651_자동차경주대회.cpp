#include <iostream>
#include <cstring>
using namespace std;
const long long BIG=1e12;
int K, N;
int cost[105], nextShop[105];
long long dist[105], cache[105];
//DP를 이용하여 curr위치에서 도착지점가는데 필요한 총 정비시간을 구한다
long long minRepairTime(int curr){
  //기저사례: 도착지점에 도달한 경우 0반환
  if(curr==N+1) return 0;
  //메모이제이션
  long long& ret=cache[curr];
  if(ret!=-1) return ret;
  ret=BIG;
  for(int next=curr+1, distSum=dist[curr]; distSum<=K&&next<=N+1; distSum+=dist[next++]){
    long long repairTime=minRepairTime(next);
    //필요한 총 정비시간이 더 짧은 경로를 발견한 경우 최신화
    if(ret>repairTime){
      ret=repairTime;
      nextShop[curr]=next;
    }
  }
  return ret+=cost[curr];
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> K >> N;
  for(int i=0; i<=N; i++) cin >> dist[i];
  for(int i=1; i<=N; i++) cin >> cost[i];
  memset(cache, -1, sizeof(cache));
  cout << minRepairTime(0) << '\n';
  int shopCnt=0;
  int visitedShop[105];
  for(int i=nextShop[0]; i!=N+1; i=nextShop[i]) visitedShop[shopCnt++]=i;
  cout << shopCnt << '\n';
  for(int i=0; i<shopCnt; i++) cout << visitedShop[i] << ' ';
}

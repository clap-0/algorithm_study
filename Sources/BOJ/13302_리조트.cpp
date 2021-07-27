#include <iostream>
#include <cstring>
using namespace std;
int N, M;
int cache[100][41];
//hasSchedule[i] = i번째 날에 일정이 있는가
bool hasSchedule[100];
//DP를 이용하여 쿠폰이 coupon개 있을 때 start번째 날부터 여름방학이 끝날 때까지
//리조트를 가기 위해 필요한 최소비용 구하기
int minimizeCost(int start, int coupon){
  //기저사례 : 여름방학이 끝난 경우 0 반환
  if(start>=N) return 0;
  //메모이제이션
  int& ret = cache[start][coupon];
  if(ret!=-1) return ret;
  //오늘은 하루이용권을 사용한다고 할 때
  //오늘 일정이 있는 경우 이용권 구매 안 함
  if(hasSchedule[start]) ret=minimizeCost(start+1, coupon);
  //일정이 없는 경우 쿠폰이 있으면 사용하고, 없으면 돈으로 지불한다
  else if(coupon>=3) ret=minimizeCost(start+1, coupon-3);
  else ret = 10000 + minimizeCost(start+1, coupon);
  //연속 3일권과 5일권을 사용한다
  ret=min(ret, 25000+minimizeCost(start+3, coupon+1));
  ret=min(ret, 37000+minimizeCost(start+5, coupon+2));
  return ret;
}
int main()
{
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int day;
    cin >> day;
    hasSchedule[day-1]=true;
  }
  memset(cache, -1, sizeof(cache));
  cout << minimizeCost(0, 0) << '\n';
}

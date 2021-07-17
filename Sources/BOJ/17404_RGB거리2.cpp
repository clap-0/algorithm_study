#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF=987654321;
int N;
int cost[1000][3], cache[3][1000][3];
//1번집의 색깔, 현재 칠하는 집번호, 현재 집의 색깔이 주어졌을 때
//DP를 이용하여 최소비용을 구한다
int painting(int init, int curr, int color){
  //메모이제이션
  int& ret = cache[init][curr][color];
  if(ret!=-1) return ret;
  //마지막 집까지 도달했을 때 마지막 집과 1번집의 색이 같으면 INF, 다르면 비용 반환
  if(curr==N-1) return ret = color!=init ? cost[curr][color] : INF;
  //다음 집을 현재 색과 다른 색으로 칠할 때 필요한 비용의 최솟값을 구한다
  ret=min(painting(init, curr+1, (color+1)%3), painting(init, curr+1, (color+2)%3)) + cost[curr][color];
  return ret;
}
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
  int ans = INF;
  memset(cache, -1, sizeof(cache));
  for(int i=0; i<3; i++) ans=min(ans,painting(i, 0, i));
  printf("%d\n", ans);
}

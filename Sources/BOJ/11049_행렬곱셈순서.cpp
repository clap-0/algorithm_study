#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INT_MAX=2147483647;
int r[500], c[500], cache[500][500];
//DP를 이용하여 행렬곱셈에 필요한 연산횟수 최솟값 구하기
//[from,to] 범위의 행렬들의 곱연산 횟수를 구한다
int countOper(int from, int to){
  //기저사례 : 곱할 행렬이 하나밖에 없을 경우 0 반환
  if(from==to) return 0;
  //메모이제이션
  int& ret = cache[from][to];
  if(ret!=-1) return ret;
  ret=INT_MAX;
  //from과 to 사이의 모든 지점 k에서 [from,k], [k+1,to] 범위의 곱연산을 구한다
  for(int k=from; k<to; k++)
    ret=min(ret, countOper(from,k)+countOper(k+1, to)+r[from]*c[k]*c[to]);
  return ret;
}
int main()
{
  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d %d", &r[i], &c[i]);
  memset(cache, -1, sizeof(cache));
  printf("%d\n", countOper(0, N-1));
}

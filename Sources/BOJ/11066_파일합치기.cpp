#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//psum[i] = 1번파일부터 i번파일까지 파일크기의 합
int psum[501], cache[501][501];
//DP를 이용하여 [from,to] 범위의 파일들을 합칠 때 필요한 최소비용 반환
int combineFiles(int from, int to){
  //기저사례 : 하나의 파일은 하나로 합치지 못한다
  if(from==to) return 0;
  //메모이제이션
  int& ret = cache[from][to];
  if(ret!=-1) return ret;
  ret=987654321;
  for(int c=from; c<to; c++)
    ret=min(ret, combineFiles(from, c)+combineFiles(c+1, to)+psum[to]-psum[from-1]);
  return ret;
}
int main()
{
  int T;
  scanf("%d", &T);
  while(T--){
    int K;
    scanf("%d", &K);
    //파일크기를 입력받아 부분합 구하기
    for(int i=1; i<=K; i++){
      int size;
      scanf("%d", &size);
      psum[i]=psum[i-1]+size;
    }
    memset(cache, -1, sizeof(cache));
    printf("%d\n", combineFiles(1,K));
  }
}

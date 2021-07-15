#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[1000], b[1000];
int cache[1000][1000];
//Top-down방식의 DP를 이용하여 LCS문제 풀기
int LCS(int idxA, int idxB){
  //기저사례 : 빈 수열의 경우 0 반환
  if(idxA==-1 || idxB==-1) return 0;
  //메모이제이션
  int& ret = cache[idxA][idxB];
  if(ret!=-1) return ret;
  //공통된 문자를 찾은 경우 두 접두사 a[..idxA]와 b[..idxB]의 LCS의 길이는
  //a[..idxA-1]와 b[..idxB-1]의 LCS길이+1이다
  if(a[idxA]==b[idxB]) return ret=1+LCS(idxA-1, idxB-1);
  //두 문자가 다른 경우 a[..idxA]와 b[..idxB]의 LCS의 길이는
  //a[..idxA-1], b[..idxB]의 LCS길이와 a[..idxA], b[..idxB-1]의 LCS길이 중 더 큰 값이다
  return ret=max(LCS(idxA-1,idxB), LCS(idxA,idxB-1));
}
int main()
{
  scanf("%s %s", a, b);
  memset(cache, -1, sizeof(cache));
  printf("%d\n", LCS(strlen(a)-1,strlen(b)-1));
}

#include <iostream>
#include <cstring>
using namespace std;
string a, b, lcs;
int cache[1000][1000], choice[1000][1000];
//Top-down방식의 DP를 이용하여 LCS의 길이 구하기
int LCS(int idxA, int idxB){
  //기저사례 : 빈 수열의 경우 0 반환
  if(idxA==-1 || idxB==-1) return 0;
  //메모이제이션
  int& ret = cache[idxA][idxB];
  if(ret!=-1) return ret;
  //공통된 문자를 찾은 경우 두 접두사 a[..idxA]와 b[..idxB]의 LCS의 길이는
  //a[..idxA-1]와 b[..idxB-1]의 LCS길이+1이다
  if(a[idxA]==b[idxB]){
    choice[idxA][idxB]=2;
    return ret=LCS(idxA-1, idxB-1)+1;
  }
  //두 문자가 다른 경우 a[..idxA]와 b[..idxB]의 LCS의 길이는
  //a[..idxA-1], b[..idxB]의 LCS길이와 a[..idxA], b[..idxB-1]의 LCS길이 중 더 큰 값이다
  ret=LCS(idxA-1,idxB);
  int tmp = LCS(idxA,idxB-1);
  if(ret<tmp){
    ret=tmp;
    choice[idxA][idxB]=0;
  }
  else choice[idxA][idxB]=1;
  return ret;
}
//접두사 a[..idxA]와 b[..idxB]의 LCS를 구한다
void reconstruct(int idxA, int idxB){
  //기저사례 : 빈 수열의 경우 리턴
  if(idxA==-1||idxB==-1) return;
  //각 인덱스에서 최적해가 나오는 인덱스를 따라 이동한다
  switch(choice[idxA][idxB]){
    case 0:
      reconstruct(idxA,idxB-1);
      break;
    case 1:
      reconstruct(idxA-1,idxB);
      break;
    //LCS의 문자인 경우 lcs에 추가한다
    default:
      lcs = a[idxA] + lcs;
      reconstruct(idxA-1,idxB-1);
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> a >> b;
  memset(cache, -1, sizeof(cache));
  int asize=a.size()-1, bsize=b.size()-1;
  cout << LCS(asize, bsize) << '\n';
  reconstruct(asize, bsize);
  if(!lcs.empty()) cout << lcs << '\n';
}

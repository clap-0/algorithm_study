#include <iostream>
#include <cstring>
using namespace std;
int N;
string S, A[100];
int cache[100];
//S의 접미사 S[curr..]을 A에 포함된 문자열로 만들 수 있는가
bool solve(int curr){
  //기저사례 : 문자열을 완성시켰으면 true 반환
  if(curr==S.size()) return true;
  //메모이제이션
  int& ret = cache[curr];
  if(ret!=-1) return ret;
  ret=false;
  //A에 포함된 문자열이 S의 접미사 S[curr..]의 접두사인지 확인하고
  //접두사라면 해당 문자열 이후의 S의 접미사를 완성시킨다
  for(int i=0; i<N; i++){
    int len=A[i].size();
    //이 문자열의 길이가 S의 남은 문자열 길이보다 길면 안된다
    if(S.size()<curr+len) continue;
    bool isMatched=true;
    for(int j=0; j<len; j++)
      if(S[curr+j]!=A[i][j]){
        isMatched=false;
        break;
      }
    if(isMatched) ret=solve(curr+len);
    if(ret==true) return ret;
  }
  return ret;
}
int main()
{
  cin >> S >> N;
  for(int i=0; i<N; i++) cin >> A[i];
  memset(cache, -1, sizeof(cache));
  printf("%d\n", solve(0));
}

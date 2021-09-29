#include <iostream>
#include <stack>
using namespace std;
// dp[a][b] = A의 접두사 A[..a]와 B의 접두사 B[..b]의 LCS의 길이
// cmmnIdx[a][b] = A[..a]와 B[..b]의 LCS에서 가장 마지막 공통문자의 인덱스번호
int dp[41][41], cmmnIdx[41][41];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int aLen, bLen;
  string A, B;
  cin >> A >> B;
  aLen = A.length(), bLen = B.length();
  // 반복적동적계획법을 이용하여 LCS의 길이 구하기
  for(int a=1; a<=aLen; a++)
    for(int b=1; b<=bLen; b++){
      if(A[a-1]!=B[b-1]){
        if(dp[a-1][b]>dp[a][b-1]){
          dp[a][b]=dp[a-1][b];
          cmmnIdx[a][b]=cmmnIdx[a-1][b];
        }
        else {
          dp[a][b]=dp[a][b-1];
          cmmnIdx[a][b]=cmmnIdx[a][b-1];
        } 
      }
      else{
        dp[a][b]=dp[a-1][b-1]+1;
        cmmnIdx[a][b]=a*41+b;
      }
    }
  // A와 B의 끝에서부터 공통문자를 찾으며 가장 긴 문자열을 만든다
  stack<char> stk;
  int aIdx=aLen, bIdx=bLen;
  while(cmmnIdx[aIdx][bIdx]!=0){
    aIdx=cmmnIdx[aIdx][bIdx]/41, bIdx=cmmnIdx[aIdx][bIdx]%41;
    stk.push(A[aIdx-1]);
    aIdx--; bIdx--;
  }
  while(!stk.empty()){
    cout << stk.top();
    stk.pop();
  }
}

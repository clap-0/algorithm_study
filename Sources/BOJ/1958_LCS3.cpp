#include <iostream>
using namespace std;

int dp[101][101][101];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string A, B, C;
  cin >> A >> B >> C;
  int aLen = A.length(), bLen = B.length(), cLen = C.length();
  
  // DP를 이용하여 Longest Common Subsequence 구하기
  for(int a = 1; a <= aLen; a++) 
    for(int b = 1; b <= bLen; b++)
      for(int c = 1; c <= cLen; c++)
        // A[..a), B[..b), C[..c)에서의 LCS의 길이는
        // A[a-1], B[b-1], C[c-1]이 같은 경우 A[..a-1), b[..b-1), C[..c-1)에서의 LCS의 길이에 1을 더한 값이다
        if(A[a - 1] == B[b - 1] && B[b - 1] == C[c - 1]) dp[a][b][c] = 1 + dp[a - 1][b - 1][c - 1];
        else dp[a][b][c] = max(dp[a - 1][b][c], max(dp[a][b - 1][c], dp[a][b][c - 1]));
  
  cout << dp[aLen][bLen][cLen] << '\n';
}

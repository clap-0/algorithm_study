#include <iostream>
#include <string>
using namespace std;

// UTF-8에서 한글은 3바이트이다.
const int BYTES = 3;
int dp[1001][1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string A, B;
  cin >> A >> B;

  // 한글 문자의 크기가 1 bytes인 것처럼 인덱스를 사용하기 위해 BYTES로 나누었다.
  int sizeA = A.size() / BYTES, sizeB = B.size() / BYTES;
  
  // DP를 사용하여 LCS를 구한다.
  for (int i = 0; i < sizeA; i++) {
    for (int j = 0; j < sizeB; j++) {
      // A[i]와 B[j]를 구한다.
      string letterA = A.substr(i * BYTES, BYTES);
      string letterB = B.substr(j * BYTES, BYTES);
      
      if (letterA == letterB) {   // A[i] == B[j] 인 경우
        dp[i + 1][j + 1] = 1 + dp[i][j];
      }
      else {                      // A[i] != B[j] 인 경우
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  cout << dp[sizeA][sizeB] << '\n';
}

#include <iostream>
#include <string>
using namespace std;

int dp[1000];
const int INF = 987654321;
const string bojStr = "BOJ";

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N;
  string blocks;
  cin >> N >> blocks;
  dp[0] = 0;
  for (int i = 1; i < N; i++) {
    dp[i] = INF;
    for (int j = i - 1; j >= 0; j--)
      // j번째 보도블럭의 글자가 i번째 보도블럭 글자의 이전 순서인 경우
      // 시작지점에서 j를 거쳐 i까지 오는데 필요한 에너지의 최솟값을 구한다.
      if ((bojStr.find(blocks[j]) + 1) % 3 == bojStr.find(blocks[i]))
        dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
  }
  
  cout << (dp[N - 1] != INF ? dp[N - 1] : -1) << '\n';
}

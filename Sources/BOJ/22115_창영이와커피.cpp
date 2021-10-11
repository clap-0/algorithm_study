#include <iostream>
#include <algorithm>
using namespace std;
const int BIG=101;
int dp[100001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, K;
  cin >> N >> K;
  // 반복적 동적계획법
  // dp[k] = 카페인을 k만큼 섭취하기 위해 필요한 커피의 최솟값
  fill(dp+1, dp+K+1, BIG);
  for(int i=0; i<N; i++){
    int C;
    cin >> C;
    // i번째 커피를 중복하여 마시는 것을 방지하기 위해 K부터 시작해 1씩 감소한다
    for(int k=K; k>=C; k--)
      if(dp[k-C]!=BIG) dp[k]=min(dp[k], dp[k-C]+1);
  }
  cout << (dp[K]!=BIG ? dp[K] : -1) << '\n';
}

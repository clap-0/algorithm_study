#include <iostream>
#include <algorithm>
using namespace std;
int dp[100001];
pair<int,int> pipe[100001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int D, P;
  cin >> D >> P;
  for(int i=1; i<=P; i++) cin >> pipe[i].first >> pipe[i].second;
  //반복적동적계획법
  //pipe를 항상 자신의 길이보다 작거나 같은 파이프부터 순차적으로 사용하도록 하기 위해 파이프의 길이에 대하여 오름차순 정렬한다
  sort(pipe, pipe+P);
  //dp[L]=C를 만족시키기 위해 dp[0]을 큰 수로 둔다
  dp[0]=987654321;
  for(int p=1; p<=P; p++){
    int L=pipe[p].first, C=pipe[p].second;
    for(int i=D; i>=L; i--) dp[i]=max(dp[i], min(dp[i-L], C));
  }
  cout << dp[D] << '\n';
}

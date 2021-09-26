#include <iostream>
#include <algorithm>
using namespace std;
int dp[100];
pair<int,int> paper[100];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, ans=0;
  cin >> N;
  // 색종이를 회전시키는 경우를 무시하고 계산하기 위해
  // 색종이의 두 변의 길이를 입력받아 둘 중 작은 변이 앞에 오도록 한다
  for(int i=0; i<N; i++){
    cin >> paper[i].first >> paper[i].second;
    if(paper[i].first>paper[i].second) swap(paper[i].first, paper[i].second);
  }
  // 색종이들을 변의 길이에 대해 오름차순으로 정렬한다
  sort(paper, paper+N);
  // 반복적동적계획법
  // dp[n] = 범위 [0,n)의 색종이를 n번째 색종이에 올릴 때 가장 많이 올릴 수 있는 개수
  for(int n=0; n<N; n++){
    // 모든 색종이는 자기자신을 포함해 최소 하나는 올릴 수 있다
    dp[n]=1;
    for(int i=0; i<n; i++)
      if(paper[n].first>=paper[i].first && paper[n].second>=paper[i].second)
        dp[n]=max(dp[n], dp[i]+1);
    ans=max(ans, dp[n]);
  }
  cout << ans << '\n';
}

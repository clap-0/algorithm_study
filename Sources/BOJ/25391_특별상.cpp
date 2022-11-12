#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> scores[200000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> scores[i].first >> scores[i].second;

  // n개의 작품을 심판이 준 점수에 대해 오름차순 정렬
  sort(scores, scores + n, [](pair<int,int> &a, pair<int,int> &b){
    return a.second > b.second;
  });

  // 심판이 먼저 점수가 높은 k명에게 본상을 수여하는 것과
  // 주최자가 임의로 m명에게 특별상을 수여한 후 본상을 수여하는 것이
  // 순서에 상관없이 결국 결과가 똑같다.
  long long ans = 0LL;
  for (int i = 0; i < k; i++) {
    ans += scores[i].first;
    scores[i] = {-1, -1};
  }
    
  sort(scores, scores + n, [](pair<int,int> &a, pair<int,int> &b){
    return a.first > b.first;
  });

  for (int i = 0; i < m; i++)
    ans += scores[i].first;

  cout << ans << '\n';
}

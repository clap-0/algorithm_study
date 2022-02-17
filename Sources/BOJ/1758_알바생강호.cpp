#include <iostream>
#include <algorithm>
using namespace std;

int tips[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> tips[i];
  // 각 사람의 팁에 대하여 내림차순 정렬
  sort(tips, tips+N, greater<int>());
  
  long long ans = 0;
  for(int i = 0; i < N; i++) ans += max(tips[i] - i, 0);
  cout << ans << '\n';
}

#include <iostream>
#include <algorithm>
using namespace std;
int P[1000];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> P[i];
  // i번째 사람이 돈을 인출할 때까지 기다려야 하는 시간을 최소화하려면
  // i-1번째 사람까지 인출하는데 걸리는 시간을 최소화시켜야한다
  // 따라서 걸리는 시간이 적은 사람부터 인출해야한다
  sort(P, P+N);
  int ans=0, last=0;
  for(int i=0; i<N; i++) ans += last += P[i];
  cout << ans << '\n';
}

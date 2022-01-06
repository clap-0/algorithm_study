#include <iostream>
#include <algorithm>
using namespace std;

int X[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, K;
  cin >> N >> K;
  for(int i=0; i<N; i++) cin >> X[i];
  
  sort(X, X+N);
  int ans;
  long long lo=X[0], hi=lo+K;
  while(lo <= hi) {
    long long mid = (lo+hi)/2, cnt = 0;
    int iter = 0;
    while(mid > X[iter]) cnt += (mid - X[iter++]);
    if(cnt > K) hi = mid-1;
    else {
      lo = mid + 1;
      ans = mid;
    }
  }
  cout << ans << '\n';
}

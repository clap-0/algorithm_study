#include <iostream>
#include <algorithm>
using namespace std;

long long t[10000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> t[i];
  
  sort(t, t+N);

  long long ans = N%2 ? t[N-1] : 0;
  int right = N%2 ? N-2 : N-1;
  for(int i=0; i<right; i++, right--){
    ans = max(ans, t[i]+t[right]);
  }
  cout << ans << '\n';
}

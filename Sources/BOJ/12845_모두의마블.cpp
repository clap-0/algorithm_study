#include <iostream>
#include <algorithm>
using namespace std;

int L[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for(int i=0; i<n; i++) cin >> L[i];
  sort(L, L+n, greater<int>());

  int ans=0;
  for(int i=1; i<n; i++) ans += L[0]+L[i];
  cout << ans << '\n';
}

#include <iostream>
using namespace std;
int n, ans;
int a[10];
void solve(int prev, int sum, int cnt){
  if(cnt==4){
    if(prev+1==n) ans=max(ans,sum);
    return;
  }
  int p=1;
  for(int i=prev+1; i<n; i++){
    p*=a[i];
    solve(i,sum+p,cnt+1);
  }
}
int main()
{
  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  solve(-1,0,0);
  cout << ans << '\n';
}

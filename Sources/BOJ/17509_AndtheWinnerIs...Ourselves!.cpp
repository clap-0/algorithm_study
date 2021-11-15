#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> DV[11];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  for(int i=0; i<11; i++) cin >> DV[i].first >> DV[i].second;
  sort(DV, DV+11);
  
  int ans=0, T=0;
  for(int i=0; i<11; i++){
    T += DV[i].first;
    ans += T+20*DV[i].second;
  }
  
  cout << ans << '\n';
}

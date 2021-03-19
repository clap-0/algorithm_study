#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n, c;
  long long ans=0;
  vector<int> x;
  cin >> n >> c;
  for(int i=0; i<n; i++){
    int house;
    cin >> house;
    x.push_back(house);
  }
  sort(x.begin(), x.end());
  long long lo=0, hi=x[n-1]-x[0];
  while(lo<=hi){
    long long mid=(lo+hi)/2;
    int cnt=1, router=x[0];
    for(int i=1; i<n; i++){
      if(x[i]>=router+mid){
        router=x[i];
        cnt++;
      }
    }
    if(cnt>=c){
      ans=max(ans, mid);
      lo=mid+1;
    }
    else hi=mid-1;
  }
  cout << ans << endl;
  return 0;
}
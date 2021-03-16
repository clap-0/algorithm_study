#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int k, n, longest=0;
  vector<long long> cable;
  cin >> k >> n;
  for(int i=0; i<k; i++){
    int length;
    cin >> length;
    cable.push_back(length);
    longest = max(longest, length);
  }
  long long lo=1, hi=longest, ans=0;
  while(lo <= hi){
    long long mid = (lo+hi)/2;
    long long sum=0;
    for(auto &length : cable) sum += length/mid;
    if(sum >= n){
      ans = max(ans, mid);
      lo = mid+1;
    }
    else hi = mid-1;
  }
  cout << ans << endl;
}

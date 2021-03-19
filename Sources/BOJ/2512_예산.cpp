#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, sum=0;
  vector<int> request(10000);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> request[i];
    sum += request[i]; //요청금액 총액 계산
  }
  cin >> m;
  //모든 요청이 배정될 수 있는 경우
  if(sum<=m) cout << *max_element(request.begin(), request.end()) << endl;
  //모든 요청이 배정될 수 없는 경우
  else {
    int lo=0, hi=m;
    //불변식 1. lo < hi
    //불변식 2. f(lo) < m < f(hi)
    while(lo+1 < hi){
      int mid = (lo+hi)/2;
      long long budget = 0;
      for(int i=0; i<n; i++)
        budget += min(request[i], mid);
      if(budget <= m) lo = mid;
      else hi = mid;
    }
    cout << lo << endl;
  }
  return 0;
}

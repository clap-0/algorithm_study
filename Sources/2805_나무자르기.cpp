#include <iostream>
#include <vector>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  vector<int> trees;
  cin >> n >> m;
  int lo=0, hi=0;
  for(int i=0; i<n; i++){
    int height;
    cin >> height;
    trees.push_back(height);
    hi = max(hi, height); //초기 hi는 가장 높은 나무 높이
  }
  //반복문불변식 1. lo < hi
  //반복문불변식 2. 절단기 높이를 x로 했을 때 얻는 나무길이 f(x)에 대해 f(lo) >= m > f(hi)
  while(lo+1<hi){
    int mid = (lo+hi)/2;
    long long sum=0; //자나깨나 오버플로우 조심
    for(auto &height : trees)
      if(height > mid) sum += height - mid; 
    if(sum >= m)
      lo = mid;
    else
      hi = mid;
  }
  cout << lo << endl;
  return 0;
}

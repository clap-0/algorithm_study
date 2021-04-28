#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int>& arr, int n, int m){
  if(arr.size()==m){ //기저사례 : 조건에 맞는 수열이 완성되면 출력
    for(int &a : arr) cout << a << ' ';
    cout << '\n';
    return;
  }
  
  int start = arr.empty() ? 1 : arr.back()+1;
  for(int i=start; i<=n; i++){
    arr.push_back(i);
    solve(arr, n, m);
    arr.pop_back();
  }
}
int main()
{
  int n, m;
  vector<int> arr; //조건을 만족하는 수열
  cin >> n >> m;
  solve(arr, n, m);
}

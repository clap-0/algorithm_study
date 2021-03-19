#include <iostream>
#include <cstring>
using namespace std;
pair<int, int> cache[41];
//n번째 피보나치수를 구할때 0과 1을 각각 몇 번 호출하는지 리턴하는 함수
pair<int, int> fibonacci(int n){ //Top-down
  if(n==0) return {1, 0};
  if(n==1) return {0, 1};
  pair<int, int>& ret = cache[n];
  if(ret.first!=-1) return ret;
  pair<int, int> fibo1 = fibonacci(n-1);
  pair<int, int> fibo2 = fibonacci(n-2);
  ret.first = fibo1.first+fibo2.first;
  ret.second = fibo1.second+fibo2.second;
  return ret;
}
int main()
{
  int t, n;
  pair<int, int> ans;
  cin >> t;
  memset(cache, -1, sizeof(cache));
  while(t--){
    cin >> n;
    ans = fibonacci(n);
    cout << ans.first << ' ' << ans.second << '\n';
  }
  return 0;
}

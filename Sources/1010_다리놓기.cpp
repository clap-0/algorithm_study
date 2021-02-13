#include <iostream>
#include <cstring>
using namespace std;
int cache[31][31];
int combination(int m, int n)
{
  if(n==1) return m; //기저사례:mC1=m
  if(m==n) return 1; //기저사례:mCm=1
  int& ret = cache[m][n];
  if(ret!=-1) return ret;
  return ret=combination(m-1, n-1)+combination(m-1, n);
}
int main()
{
  int t, n, m;
  cin >> t;
  while(t--){
    cin >> n >> m;
    memset(cache, -1, sizeof(cache));
    cout << combination(m, n) << endl;
  }
  return 0;
}

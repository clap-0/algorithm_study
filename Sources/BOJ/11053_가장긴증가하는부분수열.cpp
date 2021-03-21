#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
int cache[1001];
vector<int> a(1000);
vector<int> seq;
int lis(int here){
  int& ret=cache[here];
  if(ret!=-1) return ret;
  ret=0;
  int last = seq.back();
  for(int i=here+1; i<n; i++){
    if(a[i] > last){
      seq.push_back(a[i]);
      ret=max(ret, lis(i));
      seq.pop_back();
    }
  }
  return ++ret;
}
int main()
{
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i];
  memset(cache, -1, sizeof(cache));
  int ret=0;
  for(int i=0; i<n; i++){
    seq.push_back(a[i]);
    ret=max(ret, lis(i));
    seq.pop_back();
  }
  cout << ret << endl;
  return 0;
}

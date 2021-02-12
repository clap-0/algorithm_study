#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string cache[101][101];
string combination(int n, int m)
{
  if((n==m)||(m==0)) return "1"; //기저사례:nCn=nC0=1
  string& ret = cache[n][m];
  if(ret.length()!=0) return ret;
  string temp1, temp2;
  temp1 = combination(n-1, m-1);
  temp2 = combination(n-1, m);
  int sum=0;
  while(!temp1.empty()||!temp2.empty()||sum){ //문자열 이용한 큰 수 덧셈연산
    if(!temp1.empty()){
      sum+=temp1.front()-'0';
      temp1.erase(temp1.begin());
    }
    if(!temp2.empty()){
      sum+=temp2.front()-'0';
      temp2.erase(temp2.begin());
    }
    ret.push_back(sum%10+'0');
    sum/=10;
  }
  return ret;
}
int main()
{
  int n, m;
  string ans;
  cin >> n >> m;
  ans=combination(n, m);
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}

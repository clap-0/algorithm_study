#include <iostream>
#include <cstring>
using namespace std;
int INF = 987654321;
int cache[5001];
int countMinSacks(int n) //Top-down
{
  if(n<0) return INF; //기저사례:정확하게 봉지에 나누어지지 않을때
  if(n==0) return 0; //기저사례:봉지에 다 나누었을 때
  int& ret=cache[n];
  if(ret!=-1) return ret;
  ret=min(countMinSacks(n-3), countMinSacks(n-5))+1;
  return ret;
}
int main()
{
  int n, sacks;
  cin >> n;
  memset(cache, -1, sizeof(cache));
  sacks=countMinSacks(n);
  if(sacks>=INF) sacks=-1; 
  cout << sacks << endl;
  return 0;
}

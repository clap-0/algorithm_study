#include <iostream>
using namespace std;
const long long L=2000000000;
int ratio(long long m, long long n) { return m*100/n; } //백분율
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int c;
  cin >> c;
  while(c--){
    int n, m, curr;
    cin >> n >> m;
    curr = ratio(m, n);
    if(curr==ratio(m+L, n+L)) cout << -1 << endl; //20억게임연승해도 승률 안 오름ㅜㅜ
    else{
      long long lo=0, hi=L;
      //불변식 1.hi만큼 이기면 승률 증가
      //불변식 2.lo만큼 이기면 승률 그대로
      while(lo+1<hi){
        long long mid = (lo+hi)/2;
        int rate = ratio(m+mid, n+mid);
        if(rate-curr>=1) hi=mid;
        else lo=mid;
      }
      cout << hi << endl;
    }
  }
  return 0;
}

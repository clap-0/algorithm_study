#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const long long LIMIT=1000000;
long long lo, hi;
//lo보다 큰 최소의 n의 배수를 lo로 뺀 값
long long findIndexOf(long long n){
  if(lo%n==0) return 0;
  return n-lo%n;
}
int main()
{
  vector<bool> notSquare(LIMIT+1, true);
  cin >> lo >> hi;
  long long range = hi-lo;
  //범위 내 4의 배수들 없애기
  for(int multiof4=findIndexOf(4); multiof4<=range; multiof4+=4)
    notSquare[multiof4]=false;
  int sqrtn = int(sqrt(hi));
  for(int i=3; i<=sqrtn; i+=2){
    long long sq = (long long)i*i;
    //범위 내 sq의 배수들 없애기
    for(long long j=findIndexOf(sq); j<=range; j+=sq)
      notSquare[j]=false;
  }
  int ret=0;
  for(int i=0; i<=range; i++)
    ret += notSquare[i];
  cout << ret << endl;
  return 0;
}

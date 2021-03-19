#include <iostream>
#include <cmath>
using namespace std;
int n;
long long Y[300000], D[300000];
//양끝 열의 블록개수를 highest로 할 때 윤형이와 동혁이 건물의 블록을 빼거나 쌓는 횟수
long long countMove(long long highest){
  long long cnt=0;
  for(int i=0; i<n/2+1; i++){
    cnt += abs(Y[i]-(highest-i))+abs(D[i]-(highest-i));
    if(i!=n/2) //정중앙열 중복 방지
      cnt += abs(Y[n-i-1]-(highest-i))+abs(D[n-i-1]-(highest-i));
  }
  return cnt;
}
int main()
{
  int cnt=1;
  cin >> n;
  for(int i=0; i<n; i++) cin >> Y[i];
  for(int i=0; i<n; i++) cin >> D[i];
  //삼분탐색
  long long lo=n/2, hi=1e12;
  while(hi-lo>=3){
    long long p=(lo*2+hi)/3, q=(lo+hi*2)/3;
    if(countMove(p)>countMove(q)) lo=p;
    else hi=q;
  }
  //최종구간에서 최솟값 구하기
  long long res=1e18;
  for(int i=lo; i<=hi; i++)
    res = min(res, countMove(i));
  cout << res << endl;
  return 0;
}

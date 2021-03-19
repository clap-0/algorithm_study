#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> pole;
//전봇대간의 간격이 space일때 이동거리합
long long sumDistance(long long space){
  long long sum=0;
  for(int i=1; i<pole.size(); i++)
    sum += abs(space*i-pole[i]);
  return sum;
}
int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int pos;
    cin >> pos;
    pole.push_back(pos);
  }
  //삼분탐색
  long long lo=0, hi=pole.back();
  while(hi-lo>=3){
    long long p=(2*lo+hi)/3, q=(lo+2*hi)/3;
    if(sumDistance(p)>sumDistance(q)) lo=p;
    else hi=q;
  }
  //최종구간 내에서 최솟값 찾기
  long long res=1e18;
  for(int i=lo; i<=hi; i++)
    res = min(res, sumDistance(i));
  cout << res << endl;
}

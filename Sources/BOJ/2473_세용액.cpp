#include <iostream>
#include <algorithm>
using namespace std;
// 각 용액의 특성값
long long P[5000];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> P[i];
  sort(P, P+N);
  int A, B, C;
  long long closest=3e9;
  // 용액들중에 하나를 고르고 나머지들중에서 합이 0에 가깝도록 두 개를 고른다
  for(int a=0; a<N-2; a++){
    // 투포인터 알고리즘
    // a < lo < hi를 항상 만족한다
    int lo=a+1, hi=N-1;
    while(lo<hi){
      long long sum = P[a]+P[lo]+P[hi];
      // sum과 0사이의 차이값이 지금까지의 최솟값보다 작은 경우, 최신화시킨다
      if(closest>abs(sum)){
        closest=abs(sum);
        A=a, B=lo, C=hi;
      }
      // P[]가 오름차순 정렬되있으므로 lo가 증가하면 sum이 증가하고, hi가 감소하면 sum이 감소한다
      if(sum<0) lo++;
      else if(sum>0) hi--;
      else break;
    }
    if(closest==0) break;
  }
  cout << P[A] << ' ' << P[B] << ' ' << P[C] << '\n';
}

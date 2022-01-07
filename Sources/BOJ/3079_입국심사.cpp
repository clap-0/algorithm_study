#include <iostream>
#include <algorithm>
using namespace std;

int T[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> T[i];
  
  long long lo = 0, hi = (long long)(*max_element(T, T+N))*M;
  long long ans = 0;
  while(lo <= hi) {
    long long mid = (lo + hi)/2;
    
    // 시간이 mid만큼 주어졌을 때 심사를 받을 수 있는 사람의 수를 구한다
    long long people = 0;
    for(int i=0; i<N; i++) people += mid / T[i];
    
    if(people < M) lo = mid+1;
    else {
      hi = mid-1;
      ans = mid;
    } 
  }
  cout << ans << '\n';
}

#include <iostream>
#include <algorithm>
using namespace std;

int S[1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M, L;
  cin >> N >> M >> L;
  for(int i=0; i<M; i++) cin >> S[i];

  // 자를 수 있는 지점에서 잘랐을 때 각각의 케이크 조각의 길이를 구한다
  S[M] = L - S[M-1];
  for(int i=M-1; i>0; i--) S[i] -= S[i-1];

  while(N--) {
    int Q, ans;
    cin >> Q;
    
    int lo = 0, hi = L;
    while(lo <= hi) {
      int mid = (lo + hi) / 2;
      
      // 그리디 알고리즘을 이용하여 각각의 조각의 길이가 최소 mid만큼 되려면
      // 잘라야 하는 횟수 cnt를 구한다
      int cnt = 0, length = 0;
      for(int i=0; i<=M; i++) {
        if(S[i]+length >= mid) {
          length = 0;
          ++cnt;
        }
        else length += S[i];
      }
      
      // 가장 작은 조각의 길이의 최댓값을 구해야 하므로 lo가 바뀌는 시점에 ans를 구했다
      if(cnt >= Q+1) {
        lo = mid + 1;
        ans = mid;  
      }
      else {
        hi = mid - 1;
      }
    }
    cout << ans << '\n';
  }
}

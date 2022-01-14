#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int M;
  cin >> M;
  
  // 가장 끝의 0의 개수는 N!의 소인수 중 10의 개수에 따라 달라진다.
  // 이때 팩토리얼 수에서 2보다 5가 더 희소하게 나오므로 0의 개수는 N!에서 5의 개수가 지배하게 된다.
  // 따라서 (5*x)!의 소인수 중 5의 개수와 M을 비교해 답을 구하였다. (1 <= x <= M)
  int lo = 1, hi = M;  
  // 문제 조건을 만족하는 N이 없는 경우를 대비해 -1로 초기화
  long long ans = -1;
  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    
    // cnt : 5 * mid 이하의 수들의 소인수 중 5의 개수. 
    int cnt = mid;
    for(int k=5; k<=mid; k*=5) cnt += mid / k;
    
    if(cnt < M) lo = mid + 1;
    else if(cnt > M) hi = mid - 1;
    else {
      ans = mid * 5ll;
      break;
    }
  }
  cout << ans << '\n';
}

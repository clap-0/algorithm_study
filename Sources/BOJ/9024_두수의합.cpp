#include <iostream>
#include <algorithm>
using namespace std;

int S[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    int n, K;
    cin >> n >> K;
    for(int i=0; i<n; i++) cin >> S[i];
    
    sort(S, S+n);
    
    // 투 포인터 알고리즘
    int left=0, right=n-1, diff=2e8+1, cnt=1;
    while(left < right) {
      int sum = S[left] + S[right], tmp = abs(K-sum);
      
      // diff보다 K와의 차이가 더 가까운 두 수의 합을 찾았다면 갯수를 초기화한다
      if(diff > tmp) {
        diff = tmp;
        cnt=1;
      }
      else if(diff == tmp) cnt++;
      
      if(sum < K) left++;
      else right--;
    }
    cout << cnt << '\n';
  }
}

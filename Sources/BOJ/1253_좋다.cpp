#include <iostream>
#include <algorithm>
using namespace std;

int num[2000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> num[i];

  sort(num, num+N);

  // 투포인터 알고리즘
  int ans = 0;
  for(int n=0; n<N; n++) {
    int left = 0, right = N-1;
    while(left < right) {
      // n번째 수는 다른 두 수의 합이어야 하므로
      // left나 right가 n이면 안된다
      if(left == n) {
        left++;
        continue;
      }
      if(right == n) {
        right--;
        continue;
      }
      
      int sum = num[left] + num[right];
      if(sum == num[n]) {
        ++ans;
        break;
      }
      if(sum < num[n]) left++;
      else right--;
    }
  }
  cout << ans << '\n';
}

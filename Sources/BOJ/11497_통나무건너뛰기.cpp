#include <iostream>
#include <algorithm>
using namespace std;

int height[10000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> height[i];
    sort(height, height+N);
    // 높이가 {1,2,3,4,5,6,7,8,9,10}일 때
    // 1, 3, 5, 7, 9, 10, 8, 6, 4, 2 순으로 놓는다
    int ans=0;
    for(int i=0; i+2<N; i+=2) ans = max(ans, height[i+2]-height[i]);
    for(int i=1; i+2<N; i+=2) ans = max(ans, height[i+2]-height[i]);
    ans = max(ans, height[1]-height[0]);
    ans = max(ans, height[N-1]-height[N-2]);
    cout << ans << '\n';
  }
}

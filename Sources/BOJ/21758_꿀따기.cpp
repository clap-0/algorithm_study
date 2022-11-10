#include <iostream>
using namespace std;

int psum[100001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int honey;
    cin >> honey;
    psum[i] = honey + psum[i - 1];
  }
  
  int ans = -1;
  // 벌 - 벌 - 꿀
  for (int i = 2; i < n; i++)
    ans = max(ans, 2*(psum[n]-psum[i])+psum[i-1]-psum[1]);
  // 꿀 - 벌 - 벌
  for (int i = 2; i < n; i++)
    ans = max(ans, 2*psum[i-1]+psum[n-1]-psum[i]);
  // 벌 - 꿀 - 벌
  for (int i = 2; i < n; i++)
    ans = max(ans, psum[n-1]+psum[i]-psum[i-1]-psum[1]);
  cout << ans << '\n';
}

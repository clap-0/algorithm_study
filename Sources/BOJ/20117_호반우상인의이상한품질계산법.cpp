#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a, a + N, greater<int>());

  // a₁ ≤ a₂ ≤ a₃ ≤ a₄ 에 대해 {a₁, a₄}와 {a₂, a₃}로 묶는 것이 (a₄*2 + a₃*2)
  // {a₁, a₂, a₃, a₄}로 묶는 것(a₃*4)보다 항상 가격이 높다.
  // 따라서 품질이 높은 것과 낮은 것을 두 개씩 묶어 계산하는 것이 최대 이익이다.
  int ans = (N & 1 ? a[N >> 1] : 0);
  for (int i = 0; i < N >> 1; i++)
    ans += a[i] << 1;
  
  cout << ans << '\n';
}

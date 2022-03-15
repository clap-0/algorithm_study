#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[4000], B[4000], C[4000], D[4000];
vector<int> E, F;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

  // 배열 A와 B의 모든 원소쌍의 합 E와 배열 C와 D의 모든 합 F를 구한다
  E.resize(n * n); F.resize(n * n);
  int cnt = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      E[cnt] = A[i] + B[j];
      F[cnt++] = C[i] + D[j];
    }

  // E와 F 오름차순 정렬
  sort(E.begin(), E.end());
  sort(F.begin(), F.end());
  
  // E의 원소들과 F의 원소들 중에서 더했을 때 0이 되는 쌍의 개수를 구한다
  long long ans = 0;
  for(int i = 0; i < cnt; i++) {
    auto it = equal_range(E.begin(), E.end(), -F[i]);
    ans += it.second - it.first;
  }

  cout << ans << '\n';
}

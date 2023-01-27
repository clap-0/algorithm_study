#include <iostream>
#include <algorithm>
using namespace std;

int num[500000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> num[i];
  sort(num, num + N); // num을 오름차순으로 정렬
  
  cin >> M;
  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;
    
    // cout << binary_search(num, num + N, k) << " ";
    bool ans = false;
    int lo = 0, hi = N - 1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (num[mid] < k) lo = mid + 1;
      else if (num[mid] > k) hi = mid - 1;
      else {
        ans = true;
        break;
      }
    }
    cout << ans << ' ';
  }
}

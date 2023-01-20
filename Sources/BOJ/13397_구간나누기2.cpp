#include <iostream>
using namespace std;

int N, M;
int arr[5000];

// 배열 arr에서 점수의 최댓값이 k가 되도록 하는 구간의 개수를 반환하는 함수
int countSection(int k)
{
  int ret = 1;
  int minValue = arr[0], maxValue = arr[0];
  for (int i = 1; i < N; i++) {
    minValue = min(arr[i], minValue);
    maxValue = max(arr[i], maxValue);
    
    // 현재 구간의 점수가 k보다 큰 경우
    // i번 인덱스부터 새로운 구간으로 한다.
    if (maxValue - minValue > k) {
      ++ret;
      minValue = maxValue = arr[i];
    }
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  int ans;
  int lo = 0, hi = 10000;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    // 점수의 최댓값이 mid인 구간의 개수가 M 이하인 경우
    // mid를 더 작게 해 계산하여 점수의 최댓값의 최솟값을 구한다.
    if (countSection(mid) <= M) {
      ans = mid;
      hi = mid - 1;
    }
    else
      lo = mid + 1;
  }

  cout << ans << '\n';
}

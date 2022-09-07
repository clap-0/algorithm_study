#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int cards[500000];

// 오름차순 정렬된 cards배열에서 이분탐색을 통해
// num보다 크거나 같은 첫번째 원소의 인덱스를 반환한다.
int lowerBound(int num) {
  int lo = 0, hi = N - 1;
  int ret = N;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (cards[mid] < num)
      lo = mid + 1;
    else {
      hi = mid - 1;
      ret = mid;
    }
  }
  return ret;
}

// 오름차순 정렬된 cards배열에서 이분탐색을 통해
// num보다 큰 첫번째 원소의 인덱스를 반환한다.
int upperBound(int num) {
  int lo = 0, hi = N - 1;
  int ret = N;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (cards[mid] <= num)
      lo = mid + 1;
    else {
      hi = mid - 1;
      ret = mid;
    }
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> cards[i];
  sort(cards, cards + N);
  cin >> M;
  for (int i = 0; i < M; i++) {
    int toSearch;
    cin >> toSearch;
    // pair<int*,int*> range = equal_range(cards, cards + N, toSearch);
    // ans = range.second - range.first;
    int ans = upperBound(toSearch) - lowerBound(toSearch);
    cout << ans << ' ';
  }
}

#include <iostream>
using namespace std;

int arr[200000];
int numCount[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int lo = 0, hi = 0;
  int answer = 1;
  while (hi < N) {
    if (1 + numCount[arr[hi]] <= K) {
      answer = max(answer, hi - lo + 1);
      ++numCount[arr[hi]];
      ++hi;
    }
    else {
      --numCount[arr[lo]];
      ++lo;
    }
  }

  cout << answer << '\n';
}

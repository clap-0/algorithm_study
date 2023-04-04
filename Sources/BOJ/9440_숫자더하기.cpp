#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while (true) {
    int N;
    cin >> N;

    if (N == 0) {
      return 0;
    }

    int zeroCnt = 0;
    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
      cin >> numbers[i];
      if (numbers[i] == 0) {
        zeroCnt++;
      }
    }

    sort(numbers.begin(), numbers.end(), greater<int>());
    // 가장 마지막 두 인덱스는 0이 아니도록 한다.
    swap(numbers[N - 1 - zeroCnt], numbers[N - 1]);
    swap(numbers[N - 2 - zeroCnt], numbers[N - 2]);

    // 숫자가 클수록 작은 자릿수의 수가 되도록 한다.
    int ans = 0;
    int digits = 1;
    for (int i = 0; i < N; i++) {
      ans += numbers[i] * digits;
      if (i & 1) {
        digits *= 10;
      }
    }

    cout << ans << '\n';
  }
}
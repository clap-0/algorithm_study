#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, positiveCnt = 0, ones = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    // 양의정수의 개수와 1의 개수를 센다
    if (arr[i] > 0) {
      ++positiveCnt;
      if (arr[i] == 1)
        ++ones;
    }
  }

  // 배열 arr을 양의정수가 0과 음의정수보다 앞에 오도록 정렬한다.
  // 이때, 양의정수는 내림차순으로, 0과 음의정수는 오름차순으로 정렬한다.
  sort(arr, arr + n, [](int &a, int &b){
    if (a <= 0 && b <= 0) // 비교하는 두 수가 모두 0 혹은 음의정수면 오름차순 정렬
      return a < b;
    return a > b; // 둘 중 하나라도 양의정수면 내림차순 정렬
  });

  // 1은 다른 수와 곱하는 것보다 개별적으로 더하는 것이 더 값이 크므로 미리 ans에 더해준다.
  long long ans = 0LL + ones;
  // 1보다 큰 양의정수들을 절대값이 큰 두 수끼리 곱하여 ans에 더한다.
  // 남은 수가 하나밖에 없다면 해당 수만 더한다.
  int overOne = positiveCnt - ones;
  for (int i = 0; i < overOne; i += 2)
    ans += (i + 1 < overOne ? 1LL * arr[i] * arr[i + 1] : arr[i]);
  // 0과 음의정수들을 절대값이 큰 두 수끼리 곱하여 ans에 더한다.
  // 남은 수가 하나밖에 없다면 해당 수만 더한다.
  for (int i = positiveCnt; i < n; i += 2)
    ans += (i + 1 < n ? 1LL * arr[i] * arr[i + 1] : arr[i]);
  cout << ans << '\n';
}

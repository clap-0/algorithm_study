#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  int ans = 0;
  int maxHalf = 0;
  for (int i = 0; i < N; i++) {
    int num;  // B[i]와 일치
    cin >> num;
    // num이 0이 될 때까지 필요한 -1 연산 횟수와 /2 연산 횟수를 구한다.
    int decr = 0, half = 0;
    while (num) {
      if (num & 1) {  // num이 홀수면 -1 수행
        ++decr;
        if(--num == 0)
          break;
      }
      ++half;
      num /= 2;
    }
    // -1 연산은 배열의 값 하나하나에 수행하므로 ans에 전부 더한다.
    ans += decr;
    // /2 연산은 배열전체에 수행하므로
    // 현재까지 특정 B의 원소에 수행한 /2 연산 수의 최댓값보다 더 많이 한 횟수만 추가한다.
    if (half > maxHalf) {
      ans += half - maxHalf;
      maxHalf = half;
    }
  }

  cout << ans << '\n';
}

#include <iostream>
#include <algorithm>
using namespace std;

// dnum[i][j] = 자릿수가 i이고 j로 시작하는 감소하는 수의 개수 
int dnum[11][10];
// totalDnum[i] = 자릿수가 1 ~ i인 감소하는 수의 총 개수
int totalDnum[11];

// totalDnum과 dnum을 미리 계산한다
void init() {
  totalDnum[1] = dnum[1][0] = 1;
  for(int i = 1; i <= 10; i++) {
    totalDnum[i] += totalDnum[i - 1];
    for(int j = 1; j < 10; j++) {
      dnum[i][j] = dnum[i][j - 1] + dnum[i - 1][j - 1];
      totalDnum[i] += dnum[i][j];
    }
  }
}

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N; ++N;

  init();

  // N번째 감소하는 수의 자릿수를 구한다
  int digit = lower_bound(totalDnum, totalDnum + 11, N) - totalDnum;

  // 가장 큰 감소하는 수는 9876543210으로 11자리 이상의 감소하는 수는 없다
  if(digit == 11) {
    cout << -1 << '\n';
    return 0;
  }

  // digit자리의 수를 dnum[digit]을 이용하여 구한다
  // digit자리의 감소하는 수들 중 N번째 수의 시작숫자가 digit자리의 수가 된다
  int prev = 11;
  N -= totalDnum[digit - 1];
  while(digit) {
    int num = 0;
    while(num < prev - 1 && N - dnum[digit][num] > 0) N -= dnum[digit][num++];
    cout << num;
    prev = num;
    --digit;
  }
}

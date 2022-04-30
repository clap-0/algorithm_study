#include <iostream>
#include <cstring>
using namespace std;

int N;
int cache[100][10][1 << 10];

// 전체 N자리중 현재 자리 pos와 현재 자리의 수 num,
// 0~9 범위의 수에 대해 지금까지의 사용여부를 비트마스킹으로 표현한 chosen을 매개변수로 받아
// 길이가 N인 0~9 범위의 숫자를 모두 사용한 계단수의 개수를 반환한다
int stairNum(int pos, int num, int chosen) {
  // 길이가 N인 경우, 0부터 9까지의 수를 모두 사용했으면 1, 아니면 0 반환
  if(pos + 1 == N) return chosen + 1 == 1 << 10;

  // 메모이제이션
  int& ret = cache[pos][num][chosen];
  if(ret != -1) return ret;

  ret = 0;
  // num - 1이 0 이상이면 다음 수를 num - 1로 한다
  if(num - 1 >= 0) ret += stairNum(pos + 1, num - 1, chosen | (1 << (num - 1)));
  // num + 1이 9 이하이면 다음 수를 num + 1로 한다
  if(num + 1 <= 9) ret += stairNum(pos + 1, num + 1, chosen | (1 << (num + 1)));
  
  return ret = ret % 1000000000;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;

  memset(cache, -1, sizeof(cache));

  // 첫 번째 자리의 수가 1 ~ 9인 경우를 모두 구하여 더한다
  int ans = 0;
  for(int i = 1; i < 10; i++) {
    ans += stairNum(0, i, 1 << i);
    ans %= 1000000000;
  }

  cout << ans << '\n';
}

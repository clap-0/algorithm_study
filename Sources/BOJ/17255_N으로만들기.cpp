#include <iostream>
using namespace std;

string N;

// 문제의 역순으로 푼다. N에서 왼쪽 혹은 오른쪽에 있는 수를 빼며 한 자리 수를 만든다.
// 이때, 전부 하나의 수로 이루어진 경우 만들어지는 경우의 수가 하나이다.
int solve(int left, int right)
{
  // N[left..right]가 전부 같은 수로 되어있는 경우 1을 반환한다.
  int cnt = 1, i = left + 1;
  while (i < right && N[i] == N[left]) {
    ++cnt;
    ++i;
  }
  if (cnt == right - left)
    return 1;
  
  // N[left..right]에서 왼쪽에 있는 수를 먼저 빼는 경우와 오른쪽의 수를 먼저 빼는 경우.
  return solve(left + 1, right) + solve(left, right - 1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  cout << solve(0, N.length()) << '\n';
}

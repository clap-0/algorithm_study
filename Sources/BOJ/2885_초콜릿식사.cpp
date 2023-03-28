#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int K;
  cin >> K;
  
  int minSize, cnt;
  // K를 이진수로 나타내었을 때, 가장 왼쪽에 있는 1의 인덱스 번호
  int leftBit = 31 - __builtin_clz(K);
  // K를 이진수로 나타내었을 때, 가장 오른쪽에 있는 1의 인덱스 번호
  int rightBit = __builtin_ctz(K);
  
  if (leftBit == rightBit) {  // K가 2의 제곱수인 경우, K 만큼의 초콜릿만 필요하다.
    minSize = K;
    cnt = 0;
  }
  else {
    minSize = pow(2, 1 + leftBit);
    // 초콜릿의 크기가 2^{rightBit}가 될 때까지만 초콜릿을 쪼개므로
    cnt = leftBit - rightBit + 1;
  }

  cout << minSize << ' ' << cnt << '\n';
}

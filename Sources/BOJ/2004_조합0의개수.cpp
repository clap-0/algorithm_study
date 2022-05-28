#include <iostream>
using namespace std;

// 펙토리얼 n에서 2와 5의 개수를 반환
pair<long long,long long> getTwoAndFive(long long n) {
 pair<long long,long long> ret = {0, 0};
  for(long long i = 2, j = 5; i <= n || j <= n; i *= 2, j *= 5) {
    ret.first += n / i;
    ret.second += n / j;
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  long long N, M;
  cin >> N >> M;
  
  // nCm = n! / ((n-m)! * m!) 이므로
  // (n!의 2와 5개수) - ((n-m)!의 2와 5개수) - (m!의 2와 5개수)를 구한 뒤
  // 2와 5 중 더 작은 개수가 끝자리 0의 개수이다
  pair<long long,long long> count = getTwoAndFive(N);
  pair<long long,long long> tmp;
  tmp = getTwoAndFive(M); count = {count.first - tmp.first, count.second - tmp.second};
  tmp = getTwoAndFive(N - M); count = {count.first - tmp.first, count.second - tmp.second};
  cout << min(count.first, count.second) << '\n';
}

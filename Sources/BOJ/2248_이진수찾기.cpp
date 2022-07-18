#include <iostream>
#include <cstring>
using namespace std;

long long cache[32][32];
string result;

// n자리의 이진수에서 m개 이하의 비트만 1인 이진수의 개수를
// DP를 이용하여 구한다.
long long getBinary(int n, int m)
{
  long long &ret = cache[n][m];
  if(ret != -1)
    return ret;
  if(m == 0 || n == 0)
    return ret = 1;
  
  // getBinary(n - 1, m) : n번째 자리가 0인 경우
  // getBinary(n - 1, m - 1) : n번째 자리가 1인 경우
  return ret = getBinary(n - 1, m) + getBinary(n - 1, m - 1);
}

void solve(int n, int m, long long k)
{
  if(n == 0)
    return;
  // m이 0이면 나머지 자리의 수는 전부 0이다.
  if(m == 0)
  {
    for(int i = 0; i < n; i++)
      result += '0';
    return;
  }

  // n번째 자리가 0인 수들(pivot)이 n번째 자리가 1인 수들보다 사전순으로 앞서므로
  // k가 pivot보다 작거나 같으면 n번째 자리를 0으로 하고, 아니면 1로 한다.
  long long pivot = getBinary(n - 1, m);
  if(k <= pivot)
  {
    result += '0';
    solve(n - 1, m, k);
  }
  else
  {
    result += '1';
    solve(n - 1, m - 1, k - pivot);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, L;
  long long I;
  cin >> N >> L >> I;

  memset(cache, -1, sizeof(cache));
  getBinary(N, L);
  solve(N, L, I);

  cout << result << '\n';
}

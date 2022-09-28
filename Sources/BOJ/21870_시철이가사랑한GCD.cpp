#include <iostream>
using namespace std;

int S[200000];

// 두 수 p와 q의 최대공약수를 구하는 함수
int gcd(int p, int q)
{
  if (q == 0)
    return p;
  return gcd(q, p % q);
}

// S[from..to] 범위의 수들의 최대공약수를 구하는 함수
int gcdRange(int from, int to)
{
  int ret = S[from];
  for (int i = from + 1; i <= to; i++)
    ret = gcd(ret, S[i]);
  return ret;
}

// S[left..right] 범위의 자취방의 아름다움의 최댓값을 구한다.
int getBeauty(int left, int right)
{
  if (left == right)
    return S[left];

  int mid = (left + right + 1) / 2;
  return max(gcdRange(left, mid - 1) + getBeauty(mid, right), gcdRange(mid, right) + getBeauty(left, mid - 1));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> S[i];

  cout << getBeauty(0, N - 1) << '\n';
}

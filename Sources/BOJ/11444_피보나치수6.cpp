#include <iostream>
#include <vector>
using namespace std;

// IDENTITY: 항등행렬
const vector<int> IDENTITY = {1, 0, 0, 1};
const int MOD = 1000000007;

// 2*2 크기인 행렬 a와 b의 곱을 구현
vector<int> operator*(const vector<int>& a, const vector<int>& b) {
  return vector<int>{(int)((1LL*a[0]*b[0] + 1LL*a[1]*b[2])%MOD), (int)((1LL*a[0]*b[1] + 1LL*a[1]*b[3])%MOD), (int)((1LL*a[2]*b[0] + 1LL*a[3]*b[2])%MOD), (int)((1LL*a[2]*b[1] + 1LL*a[3]*b[3])%MOD)};
}

// 2*2 크기의 행렬 A의 n제곱을 분할정복을 통해 구하는 함수
vector<int> pow(const vector<int>& A, long long n) {
  // A^0 = I
  if(n == 0) return IDENTITY;
  
  // n이 홀수면 A^n = A * A^(n-1)
  if(n & 1) return pow(A, n - 1) * A;
  
  // A^n = A^(n/2) * A^(n/2)
  vector<int> half = pow(A, n / 2);
  return half * half;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  long long n;
  cin >> n;

  //      | 1  1 |            | fib(n+1)  fib(n)     |
  // 행렬 | 1  0 | 의 n제곱은  | fib(n)    fib(n - 1) | 과 같다
  const vector<int> initial = {1, 1, 1, 0};
  vector<int> poweredMatrix = pow(initial, n);
  cout << poweredMatrix[1] << '\n';
}

#include <iostream>
using namespace std;

// psum[i] = 가장 앞에 있는 비트가 i번이하의 비트인 수들의 1의 개수의 합
// 입력의 최대값인 10¹⁶의 이진수값에서 가장 앞에 있는 비트가 54번이므로 배열의 크기를 55로 하였다
long long psum[55];

// n이하의 모든 수에 대하여 1의 개수의 합을 구한다
long long solve(long long n) {
  long long ans = n & 1;  // n의 0번비트가 1이면 1, 0이면 0.
  
  // n의 가장 앞에 있는 비트의 위치 i에 대하여
  // (가장 앞 비트의 위치가 i번미만인 비트들의 1의 개수의 합) + (가장 앞 비트가 i번째인 n이하의 수의 개수)를 구하고,
  // n에서 i번째 비트를 없애는 것을 반복한다
  for(int i = 54; i > 0; i--) 
    if(n & (1LL << i)) ans += psum[i - 1] + ((n -= (1LL << i)) + 1);
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  long long A, B;
  cin >> A >> B;
  
  psum[0] = 1; // 1밖에 없다
  for(int i = 1; i <= 54; i++)
    psum[i] = 2 * psum[i - 1] + (1LL << i); // [ 1 << i , 1 << i+1 ) 범위의 이진수 표현은 [ 0 , 1 << i ) 범위의 이진수 표현의 i번째 비트가 1인 것과 같으므로

  cout << solve(B) - solve(A - 1) << '\n';
}

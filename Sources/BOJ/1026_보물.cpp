#include <iostream>
#include <algorithm>
using namespace std;
int A[50], B[50];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, S=0;
  cin >> N;
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<N; i++) cin >> B[i];
  sort(A, A+N);
  sort(B, B+N, greater<int>());
  // S의 값을 최소로 하기위해 A의 i번째로 작은 수와 B의 i번째로 큰 수를 곱한다
  for(int i=0; i<N; i++) S += A[i]*B[i];
  cout << S << '\n';
}

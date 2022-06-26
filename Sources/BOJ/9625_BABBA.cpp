#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int K;
  cin >> K;

  int A = 1, B = 0;
  for(int i = 0; i < K; i++)
    B += B ^ A ^ (A = B); // A = B, B += A를 동시에 수행

  cout << A << ' ' << B << '\n';
}

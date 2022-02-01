#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int D, K;
  cin >> D >> K;
  
  // D일차일 때 필요한 A와 B의 개수를 구한다
  pair<int,int> dduk[3];
  dduk[0] = {1, 0}, dduk[1] = {0, 1};
  for(int i = 2; i < D; i++)
    dduk[i%3] = {dduk[(i-1)%3].first+dduk[(i-2)%3].first, dduk[(i-1)%3].second+dduk[(i-2)%3].second};
  
  // p * A + q * B == K를 만족하는 A와 B를 구한다
  int A = 1, B, p = dduk[(D-1)%3].first, q = dduk[(D-1)%3].second;
  while((K - A * p) % q) ++A;
  B = (K - A * p) / q;
  
  cout << A << '\n' << B << '\n';
}

#include <iostream>
#include <algorithm>
using namespace std;
int houses[200000];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++) cin >> houses[i];
  sort(houses, houses+N);
  // 모든 집의 중간값
  cout << houses[(N-1)/2] << '\n';
}

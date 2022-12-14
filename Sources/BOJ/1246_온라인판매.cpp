#include <iostream>
#include <algorithm>
using namespace std;

int P[1000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
    cin >> P[i];
  
  sort(P, P + M, greater<int>());
  int price, profit = 0;
  for (int i = 0; i < min(N,M); i++)
    if (profit < (i + 1) * P[i]) {
      profit = (i + 1) * P[i];
      price = P[i];
    }
  
  cout << price << ' ' << profit << '\n';
}

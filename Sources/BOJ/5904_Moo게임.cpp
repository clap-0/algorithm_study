#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> L;

char solve(int N)
{
  if (N <= L[0])
    return (N == 1 ? 'm' : 'o');

  int idx = upper_bound(L.begin(), L.end(), N) - L.begin() - 1;
  N -= L[idx];
  int middle = L[0] + idx + 1;
  if (N <= middle)
    return (N == 1 ? 'm' : 'o');
  else
    return solve(N - middle);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  
  L.push_back(3);
  for (int i = 1; L.back() < N; i++)
    L.push_back(2 * L.back() + L.front() + i);

  cout << solve(N) << '\n';
}

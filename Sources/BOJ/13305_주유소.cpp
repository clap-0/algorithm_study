#include <iostream>
using namespace std;

int dist[100000], costs[100000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  for (int i = 0; i < N - 1; i++)
    cin >> dist[i];
  for (int i = 0; i < N; i++)
    cin >> costs[i];

  long long lastCost = costs[0];
  long long ans = lastCost * dist[0];
  for (int i = 1; i < N; i++) {
    if (lastCost > costs[i])
      lastCost = costs[i];
    ans += lastCost * dist[i];
  }
  cout << ans << '\n';
}

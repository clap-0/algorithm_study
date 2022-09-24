#include <iostream>
#include <vector>
using namespace std;

int dp[10001];
vector<pair<int,int> > adj[10001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int N, D;
  cin >> N >> D;
  for (int i = 0; i < N; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[v].push_back({u, w});
  }

  for (int i = 1; i <= D; i++) {
    dp[i] = dp[i - 1] + 1;
    for (auto &p : adj[i])
      dp[i] = min(dp[i], dp[p.first] + p.second);
  }

  cout << dp[D] << '\n';
}

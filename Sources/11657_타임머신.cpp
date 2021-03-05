#include <iostream>
#include <vector>
using namespace std;
int n, m;
const int MAX_N=501, INF=987654321;
vector<pair<int, int> > adj[MAX_N];
//벨만포드 알고리즘
//int로 하면 출력초과 뜸
vector<long long> bellmanFord(int src){
  vector<long long> upper(n+1, INF);
  upper[src]=0;
  bool updated;
  for(int iter=0; iter<n; iter++){
    updated = false;
    for(int here=1; here<=n; here++)
      for(auto &p : adj[here]){
        int there = p.first;
        int cost = p.second;
        if(upper[here]!=INF&&upper[there] > upper[here] + cost){
          upper[there] = upper[here] + cost;
          updated = true;
        }
      }
    if(!updated) break;
  }
  if(updated) upper.clear();
  return upper;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }
  vector<long long> shortest = bellmanFord(1);
  if(shortest.empty()) cout << -1 << endl; // 음수사이클이 있는 경우
  else
    for(int i=2; i<=n; i++)
      cout << ((shortest[i]!=INF) ? shortest[i] : -1) << endl;
  return 0;
}

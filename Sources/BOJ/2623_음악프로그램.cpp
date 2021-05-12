#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=1001;
int n, m;
vector<int> adj[MAX_N];
vector<int> indegrees(MAX_N);
vector<int> topologicalSort(){
  queue<int> q;
  vector<int> res;
  for(int i=1; i<=n; i++)
    if(indegrees[i]==0) q.push(i);
  for(int i=0; i<n; i++){
    if(q.empty()) return vector<int>(1,0);
    int curr = q.front();
    q.pop();
    for(int next : adj[curr])
      if(--indegrees[next]==0) q.push(next);
    res.push_back(curr);
  }
  return res;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int singers;
    cin >> singers;
    int prev, curr;
    cin >> prev;
    for(int j=1; j<singers; j++){
      cin >> curr;
      adj[prev].push_back(curr);
      indegrees[curr]++;
      prev = curr;
    }
  }
  vector<int> ans = topologicalSort();
  for(int order : ans) cout << order << '\n';
}

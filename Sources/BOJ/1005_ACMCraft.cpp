#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int> > adj; //인접리스트
vector<int> indegrees; //indegrees[i] = i로 들어오는 간선의 수
vector<int> cost, finished; //건설에 걸리는시간과 건설완료하는데 걸리는 최소시간
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    adj.clear(); adj.resize(n+1);
    indegrees.clear(); indegrees.resize(n+1);
    cost.clear(); cost.resize(n+1);
    for(int i=1; i<=n; i++) cin >> cost[i];
    for(int i=0; i<k; i++){
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      indegrees[y]++;
    }
    //위상정렬 알고리즘
    queue<int> q;
    finished.clear(); finished.resize(n+1, 0);
    for(int i=1; i<=n; i++)
      if(indegrees[i]==0){
        q.push(i);
        finished[i] = cost[i];
      }
    for(int i=0; i<=n; i++){
      int curr = q.front();
      q.pop();
      for(int next : adj[curr]){
        finished[next] = max(finished[next], finished[curr]+cost[next]);
        if(--indegrees[next]==0) q.push(next);
      }
    }
    int w;
    cin >> w;
    cout << finished[w] << '\n';
  }
}

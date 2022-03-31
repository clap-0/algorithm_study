#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
typedef pair<int,int> pii;

vector<pii> adj[5001];  // adj[u] : u에서 v로 가는 간선의 가중치를 {w, v}로 저장
int dist[5001]; // dist[i] : s에서 i까지의 최단거리

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  // 입력
  int n, m, s, t;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }
  cin >> s >> t;

  // 다익스트라 알고리즘
  for(int i = 1; i <= n; i++) dist[i] = INF;  // INF로 초기화
  priority_queue<pii, vector<pii>, greater<pii> > pq; // 오름차순 정렬
  pq.push({0, s});
  dist[s] = 0;
  while(!pq.empty()) {
    int cost = pq.top().first, curr = pq.top().second;
    pq.pop();
    if(dist[curr] < cost) continue; // 이미 이전에 cost보다 적은 비용으로 curr에 도달했다면 넘긴다
    if(curr == t) break;  // t에 도달한 경우 종료
    for(pii& p : adj[curr]) {
      int nextCost = cost + p.first, next = p.second;
      if(dist[next] > nextCost) {
        dist[next] = nextCost;
        pq.push({nextCost, next});
      }
    }
  }

  cout << dist[t] << '\n';
}

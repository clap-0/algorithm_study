#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int> > adj[10001];
// weight[i] = 공장이 있는 섬 S에서 섬 i까지 옮길 수 있는 중량의 최댓값
int weight[10001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M, S, E;
  cin >> N >> M;
  for(int i=0; i<M; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    adj[A].push_back({B, C});
    adj[B].push_back({A, C});
  }
  cin >> S >> E;

  // 다익스트라 알고리즘을 변형하였다
  priority_queue<pair<int, int> > pq;
  pq.push({1e9, S});
  while(!pq.empty()) {
    int w = pq.top().first, curr = pq.top().second;
    pq.pop();
    // curr 섬에 w보다 큰 중량의 물건을 옮기는 방법이 있는 경우 패스
    if(weight[curr] > w) continue;
    for(auto &p : adj[curr]) {
      int next = p.first, limit = min(w, p.second);
      if(weight[next] < limit) {
        weight[next] = limit;
        pq.push({limit, next});
      }
    }
  }
  cout << weight[E] << '\n';
}

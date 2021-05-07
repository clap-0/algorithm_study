#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX=32001;
vector<int> adj[MAX]; //인접리스트
vector<int> indegrees(MAX); //indegrees[i] = i로 들어오는 간선의 수
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    indegrees[b]++;
  }
  
  //위상정렬 알고리즘
  priority_queue<int, vector<int>, greater<int> > pq; //쉬운문제부터 풀어야 하므로 최소힙 사용
  vector<int> order;
  
  for(int i=1; i<=n; i++)
    if(indegrees[i]==0) pq.push(i);
  
  for(int i=1; i<=n; i++){
    int curr = pq.top();
    pq.pop();
    for(int next : adj[curr])
      if(--indegrees[next]==0) pq.push(next);
    order.push_back(curr);
  }
  
  for(int problem : order) cout << problem << ' ';
}

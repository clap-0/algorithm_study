#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int ans;
vector<int> adj[10001];
vector<int> hacked(10001);
bool visited[10001];

void dfs(int here) {
  visited[here] = true;
  ans = max(ans, ++hacked[here]);
  for(int there : adj[here])
    if(!visited[there])
      dfs(there);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for(int i=0; i<M; i++) {
    int A, B;
    cin >> A >> B;
    adj[A].push_back(B);
  }
  
  for(int i=1; i<=N; i++) {
    memset(visited, false, sizeof(visited));
    dfs(i);
  }

  for(int i=1; i<=N; i++)
    if(hacked[i] == ans)
      cout << i << ' ';
}

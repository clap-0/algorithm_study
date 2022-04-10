#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 100000, LOG_N = 17;

vector<pair<int,int> > adj[MAX_N];
int parent[MAX_N][LOG_N + 1];
int depth[MAX_N];
int minRoad[MAX_N][LOG_N + 1], maxRoad[MAX_N][LOG_N + 1];


void makeTree(int curr) {
  for(auto &next : adj[curr]) {
    int child = next.first;
    if(depth[child] == -1) {
      depth[child] = depth[curr] + 1;
      parent[child][0] = curr;
      minRoad[child][0] = maxRoad[child][0] = next.second;
      makeTree(child);
    }
  }
}

void init(int N) {
  memset(depth, -1, sizeof(depth));
  memset(parent, -1, sizeof(parent));
  depth[0] = 0;
  makeTree(0);

  for(int j = 0; j < LOG_N; j++) 
    for(int i = 1; i < N; i++) 
      if(parent[i][j] != -1) {
        parent[i][j + 1] = parent[parent[i][j]][j];
        if(parent[i][j + 1] != -1) {
          minRoad[i][j + 1] = min(minRoad[i][j], minRoad[parent[i][j]][j]);
          maxRoad[i][j + 1] = max(maxRoad[i][j], maxRoad[parent[i][j]][j]);
        }
      }
}

void solve(int u, int v) {
  int shortest = 1000001, longest = -1;

  if(depth[u] < depth[v]) swap(u, v);

  int diff = depth[u] - depth[v];
  while(diff) {
    int jump = __builtin_ctz(diff);
    shortest = min(shortest, minRoad[u][jump]);
    longest = max(longest, maxRoad[u][jump]);
    u = parent[u][jump];
    diff &= (diff - 1);
  }

  if(u != v) {
    for(int i = LOG_N; i >= 0; i--)
      if(parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
        shortest = min(shortest, min(minRoad[u][i], minRoad[v][i]));
        longest = max(longest, max(maxRoad[u][i], maxRoad[v][i]));
        u = parent[u][i];
        v = parent[v][i];
      }
      shortest = min(shortest, min(minRoad[u][0], minRoad[v][0]));
      longest = max(longest, max(maxRoad[u][0], maxRoad[v][0]));
  }

  cout << shortest << " " << longest << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, K;
  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int A, B, C;
    cin >> A >> B >> C; A--; B--;
    adj[A].push_back({B, C});
    adj[B].push_back({A, C});
  }

  init(N);

  cin >> K;
  for(int i = 0; i < K; i++) {
    int D, E;
    cin >> D >> E; D--; E--;
    solve(D, E);
  }
}

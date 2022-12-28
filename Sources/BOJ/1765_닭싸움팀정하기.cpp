#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int ds[1001]; // disjoint set
vector<int> enemys[1001];

int find(int n)
{
  if (ds[n] < 0)
    return n;
  return ds[n] = find(ds[n]);
}

void merge(int u, int v)
{
  u = find(u);
  v = find(v);
  if (u == v)
    return;
  ds[v] = u;
}

void mergeEnemyOfMyEnemy(int u, int v)
{
  // v의 원수의 원수는 u의 친구
  for (int candidate : enemys[v]) {
    if (u != candidate) {
      bool canBeFriend = true;
      for (int myEnemy : enemys[u]) {
        if (candidate == myEnemy) {
          canBeFriend = false;
          break;
        }
      }
      if (canBeFriend)
        merge(u, candidate);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  memset(ds, -1, sizeof(ds));
  for (int i = 0; i < m; i++) {
    char opt;
    int p, q;
    cin >> opt >> p >> q;
    if (opt == 'E') {
      mergeEnemyOfMyEnemy(p, q);
      mergeEnemyOfMyEnemy(q, p);
      enemys[p].push_back(q);
      enemys[q].push_back(p);
    }
    else {
      merge(p, q);
    }
  }
  
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (ds[i] < 0)
      ans++;
  cout << ans << '\n';
}

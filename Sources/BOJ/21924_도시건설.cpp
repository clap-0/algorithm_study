#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int uf[100001]; // uf[i] = i가 속한 집합의 번호
pair<int,pair<int,int> > edges[500000];

// n이 속한 집합의 번호를 찾는 함수
int find(int n)
{
  if (uf[n] < 0)
    return n;
  return uf[n] = find(uf[n]);
}

// u가 속한 집합에 v가 속한 집합을 합치는 함수
// 두 집합이 같은 집합인 경우 false를 반환한다.
bool merge(int u, int v)
{
  u = find(u);
  v = find(v);
  if (u == v)
    return false;
  uf[v] = u;
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  long long ans = 0LL;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {w, {u, v}};
    ans += w;
  }

  memset(uf, -1, sizeof(uf));
  sort(edges, edges + M);

  int cnt = 0;
  for (int i = 0; i < M; i++)
    if (merge(edges[i].second.first, edges[i].second.second)) {
      ans -= edges[i].first;
      if (++cnt == N - 1)
        break;
    }
  
  cout << (cnt == N - 1 ? ans : -1) << '\n';
}

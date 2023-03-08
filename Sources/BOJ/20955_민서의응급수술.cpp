#include <iostream>
#include <cstring>
using namespace std;

int uf[100001];

// 유니온 파인드 알고리즘

int find(int u)
{
  if (uf[u] < 0) {
    return u;
  }
  return uf[u] = find(uf[u]);
}

bool merge(int u, int v)
{
  u = find(u);
  v = find(v);
  if (u == v) {
    return false;
  }

  uf[v] = u;
  return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;

  memset(uf, -1, sizeof(uf));

  int disconnect = 0;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    if (!merge(u, v)) { // u와 v 사이의 시냅스로 인해 사이클이 되는 경우, 연결 끊기
      ++disconnect;
    }
  }

  // 필요한 연결 횟수 = 목표로 하는 트리 형태의 시냅스 수 - 현재 연결되어 있는 시냅스 수
  int connect = (N - 1) - (M - disconnect);

  cout << connect + disconnect << '\n';
}

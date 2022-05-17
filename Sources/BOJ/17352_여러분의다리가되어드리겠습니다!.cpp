#include <iostream>
using namespace std;

int uf[300001];

// 유니온 파인드
int find(int n) {
  if(uf[n] == 0) return n;
  return uf[n] = find(uf[n]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return;
  uf[v] = u;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;
  // 무너지지 않은 다리들끼리 유니온파인드로 연결한다
  for(int i = 2; i < N; i++) {
    int u, v;
    cin >> u >> v;
    merge(u, v);
  }

  // 루트노드 번호가 다른 두 노드를 출력한다
  for(int i = 1; i < N; i++) 
    if(find(i) != find(i + 1)) {
      cout << i << ' ' << i + 1 << '\n';
      return 0;
    }
}

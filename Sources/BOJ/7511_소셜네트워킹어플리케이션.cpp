#include <iostream>
#include <vector>
using namespace std;

// 유니온파인드
vector<int> uf;

int find(int n) {
  if(uf[n] < 0) return n;
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

  int T;
  int n, m, k, u, v;
  cin >> T;
  for(int tc = 1; tc <= T; tc++) {
    cin >> n >> k;
    uf = vector<int>(n, -1);
    // 친구관계인 사람끼리 유니온파인드로 묶는다
    for(int i = 0; i < k; i++) {
      cin >> u >> v;
      merge(u, v);
    }
    cin >> m;
    cout << "Scenario " << tc << ":\n";
    for(int i = 0; i < m; i++) {
      cin >> u >> v;
      u = find(u); v = find(v);
      cout << (u == v) << '\n'; // u와 v가 친구관계인지 확인한다
    }
    cout << '\n';
  }
}

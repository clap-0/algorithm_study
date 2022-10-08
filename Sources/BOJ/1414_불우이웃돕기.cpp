#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int uf[50];
vector<pair<int, pair<int,int> > > adj;

// 유니온파인드 알고리즘
int find(int n)
{
  if (uf[n] < 0)
    return n;
  return uf[n] = find(uf[n]);
}

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
  
  int N, sum = 0;
  cin >> N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      char ch;
      cin >> ch;
      if (ch == '0')  // 문자가 0인 경우, i와 j를 연결하는 랜선 없음
        continue;
      // 랜선의 길이를 문자에서 숫자로 변환하여 저장한다.
      int length = ('a' <= ch && ch <= 'z' ? ch - 'a' + 1 : ch - 'A' + 27);
      adj.push_back({length, {i, j}});
      sum += length;
    }

  sort(adj.begin(), adj.end());
  fill(uf, uf + N, -1);
  // 크루스칼의 최소스패닝트리 알고리즘
  int cnt = 0;
  for (auto &p : adj) {
    int u = p.second.first, v = p.second.second;
    if (merge(u, v)) {
      sum -= p.first;
      if (++cnt == N - 1)
        break;
    }
  }

  cout << (cnt == N - 1 ? sum : -1) << '\n';
}

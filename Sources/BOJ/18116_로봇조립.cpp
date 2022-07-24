#include <iostream>
#include <cstring>
using namespace std;

int uf[1000001];

// 유니온파인드 알고리즘
int find(int n)
{
  if(uf[n] < 0)
    return n;
  return uf[n] = find(uf[n]);
}

void merge(int u, int v)
{
  u = find(u);
  v = find(v);
  if(u == v)
    return;
  uf[u] += uf[v];
  uf[v] = u;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  memset(uf, -1, sizeof(uf));
  int N;
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    char order;
    cin >> order;
    if(order == 'I')
    {
      int a, b;
      cin >> a >> b;
      merge(a, b);
    }
    else 
    {
      int c;
      cin >> c;
      cout << -uf[find(c)] << '\n';
    }
  }
}

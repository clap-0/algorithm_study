#include <iostream>
#include <algorithm>
using namespace std;

int P[500000], Q[500000];

int main()
{
  ios_base::sync_with_stdio(false);       
  cin.tie(0); cout.tie(0);

  int n, m, c1, c2;
  cin >> n >> m >> c1 >> c2;
  for(int i=0; i<n; i++) cin >> P[i];
  for(int i=0; i<m; i++) cin >> Q[i];
  
  sort(P, P+n);
  sort(Q, Q+m);

  // 투포인터 알고리즘
  int p = 0, q = 0;
  int xDist = 2e9, cnt = 1;
  while(q != m) {
    int tmp = abs(P[p] - Q[q]);
    if(xDist > tmp) {
      xDist = tmp;
      cnt = 1;
    }
    else if(xDist == tmp) ++cnt;
    
    // 두 포인터 중 가리키는 값이 더 작은 포인터를 증가시켜야
    // abs(P[p] - Q[q])가 더 작아진다
    if(P[p] < Q[q] && p + 1 < n) ++p;
    else if(P[p] > Q[q] && q + 1 < m) ++q;
    else n - p > m - q ? ++p : ++q;
  }

  cout << xDist + abs(c1 - c2) << ' ' << cnt << '\n';
}

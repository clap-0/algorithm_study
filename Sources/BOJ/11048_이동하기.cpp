#include <iostream>
using namespace std;

int cache[1001][1001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++) {
      int candys;
      cin >> candys;
      cache[i + 1][j] = max(candys + cache[i][j], cache[i + 1][j]);
      cache[i][j + 1] = max(candys + cache[i][j], cache[i][j + 1]);
      cache[i + 1][j + 1] = max(candys + cache[i][j], cache[i + 1][j + 1]);
    }
  
  cout << cache[N][M] << ' ';
}

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int arr[100];
// cache[i][j] = arr의 [0..i] 범위에서 arr[i]가 무조건 구간에 포함되도록 j개의 구간으로 나눌 때
// 구간에 속한 수들의 최댓값
int cache[100][51]; 

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M;
  cin >> N >> M;
  // cache를 매우 작은 수로 초기화
  fill((int*)cache, (int*)(cache + N), -INF);
  for(int i = 0; i < N; i++)
  {
    cin >> arr[i];
    cache[i][0] = 0;
  }

  cache[0][1] = arr[0];
  cache[1][1] = max(arr[0] + arr[1], arr[1]);
  for(int i = 2; i < N; i++)
    for(int j = 1; j <= M; j++)
    {
      // arr[i]가 바로 이전 구간에 속하는 경우
      cache[i][j] = cache[i - 1][j] + arr[i];
      // arr[i]가 새로운 구간에 속하는 경우
      for(int k = i - 2; k >= 0; k--)
        cache[i][j] = max(cache[i][j], arr[i] + cache[k][j - 1]);
    }
  
  int ans = -INF;
  for(int i = 0; i < N; i++)
    ans = max(ans, cache[i][M]);
  
  cout << ans << '\n';
}

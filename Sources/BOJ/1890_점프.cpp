#include <iostream>
using namespace std;

long long cache[100][100];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, jump;
  cin >> N;

  // cache[i][j] = 가장 왼쪽 위칸(0행 0열)에서 i행 j열로 점프를 통해 이동하는 방법의 수
  cache[0][0] = 1LL;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++) {
      cin >> jump;
      if(cache[i][j] && jump) {
        if(i + jump < N) cache[i + jump][j] += cache[i][j];
        if(j + jump < N) cache[i][j + jump] += cache[i][j];
      }
    }

  cout << cache[N - 1][N - 1] << '\n';
}

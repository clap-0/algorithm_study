#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
const int d[7][3] = {
  {1,0,0}, {0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,1,1},
};

int dp[2][51][51][51];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int S, A, B, C;
  cin >> S >> A >> B >> C;

  dp[0][A][B][C] = 1;
  for(int i = 0; i < S; i++) {
    fill((int*)(&dp[(i + 1) % 2]), (int*)(dp[(i + 1) % 2] + 51), 0);
    
    for(int a = 0; a <= A; a++)
      for(int b = 0; b <= B; b++)
        for(int c = 0; c <= C; c++)
          if(dp[i % 2][a][b][c])
            for(int j = 0; j < 7; j++) {
              int da = a - d[j][0], db = b - d[j][1], dc = c - d[j][2];
              if(da < 0 || db < 0 || dc < 0) continue;
              dp[(i + 1) % 2][da][db][dc] += dp[i % 2][a][b][c];
              dp[(i + 1) % 2][da][db][dc] %= MOD;
            }
  }

  cout << dp[S % 2][0][0][0] << '\n';
}

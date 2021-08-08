#include <iostream>
#include <cstring>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, M, best=-1;
  //토끼의 처음 위치
  pair<int,int> R;
  char map[1000][1000];
  int dp[1000][1000];
  cin >> N >> M;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++){
      cin >> map[i][j];
      if(map[i][j]=='R') R={i,j};
    }
  //반복적동적계획법
  //dp[i][j] = i행j열에 갔을 때 얻을 수 있는 당근의 최대개수. 해당 위치로 갈 수 없으면 -1
  memset(dp, -1, sizeof(dp));
  dp[R.first][R.second]=0;
  for(int c=R.second+1; c<M; c++)
    for(int r=0; r<N; r++){
      if(map[r][c]=='#') continue;
      //r행c열로 올 수 있는 c-1열의 칸들 중에서 당근을 가장 많이 얻었던 칸을 통해 온다
      dp[r][c]=dp[r][c-1];
      if(r!=0) dp[r][c]=max(dp[r][c], dp[r-1][c-1]);
      if(r!=N-1) dp[r][c]=max(dp[r][c], dp[r+1][c-1]);
      //r행c열에 당근이 있고, 이 위치로 오는 방법이 있다면 이 위치까지 올 때 얻는 당근개수+1
      if(map[r][c]=='C'&&dp[r][c]!=-1) dp[r][c]++;
      //r행c열에 쪽문이 있다면 정보섬 빠져나가며 얻는 당근의 최대개수를 최신화한다
      else if(map[r][c]=='O') best=max(best, dp[r][c]);
    }
  cout << best << '\n';
}

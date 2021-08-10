#include <iostream>
#include <queue>
using namespace std;
const int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};
char map[1000][1000];
bool discovered[1000][1000][11];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, M, K;
  queue<pair<pair<int,int>,int> > Q;
  cin >> N >> M >> K;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++) cin >> map[i][j];
  //너비우선탐색 알고리즘
  Q.push({{0,0},0});
  discovered[0][0][0]=true;
  int cnt=1, ans=-1;
  while(!Q.empty()){
    int qsize=Q.size();
    for(int i=0; i<qsize; i++){
      int y=Q.front().first.first, x=Q.front().first.second, k=Q.front().second;
      Q.pop();
      if(y==N-1&&x==M-1){
        ans=cnt;
        break;
      }
      for(int d=0; d<4; d++){
        int ny=y+dy[d], nx=x+dx[d], nk=k+map[ny][nx]-'0';
        if(ny<0||nx<0||ny>=N||nx>=M) continue;
        if(nk>K || discovered[ny][nx][nk]) continue;
        Q.push({{ny,nx},nk});
        discovered[ny][nx][nk]=true;
      }
    }
    if(ans!=-1) break;
    cnt++;
  }
  cout << ans << '\n';
}

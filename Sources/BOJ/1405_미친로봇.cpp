#include <iostream>
using namespace std;
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
// 각각 동서남북 방향으로 가는 확률
double probability[4];
bool visited[29][29];
// 깊이우선탐색으로 방문하지 않은 곳만을 방문하도록 한다
double dfs(int y, int x, int cnt){
  // 정해진 횟수만큼 모두 움직인 경우 1 반환
  if(cnt==0) return 1.0;
  visited[y][x]=true;
  double ret=0.0;
  for(int i=0; i<4; i++){
    int ny=y+d[i][0], nx=x+d[i][1];
    if(!visited[ny][nx]){
      ret+=probability[i]*dfs(ny, nx, cnt-1);
    }
  }
  visited[y][x]=false;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<4; i++){
    int percentage;
    cin >> percentage;
    probability[i]=percentage/100.0;
  }
  cout << fixed;
  cout.precision(10);
  cout << dfs(14, 14, N) << '\n';
}

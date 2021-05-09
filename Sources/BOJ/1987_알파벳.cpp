#include <iostream>
#include <vector>
using namespace std;
int r, c;
int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};
char board[20][20];
bool visited[26]; //해당 알파벳을 지나왔는가?
//깊이우선탐색을 이용한 풀이
int getMaxMove(int y, int x){
  visited[board[y][x]-'A'] = true;
  int ret=0;
  for(int i=0; i<4; i++){
    int ny=y+dy[i], nx=x+dx[i];
    if(ny<0||nx<0||ny>=r||nx>=c) continue;
    if(!visited[board[ny][nx]-'A']){
      ret = max(ret, getMaxMove(ny, nx));
    }
  }
  visited[board[y][x]-'A'] = false;
  return ret+1;
}
int main()
{
  cin >> r >> c;
  for(int i=0; i<r; i++)
    for(int j=0; j<c; j++)
      cin >> board[i][j];
  cout << getMaxMove(0, 0) << '\n';
}

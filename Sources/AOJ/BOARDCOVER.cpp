#include <iostream>
using namespace std;
//빈 칸을 덮는 4가지 방법
const int type[4][3][2]={
  {{0,0},{1,0},{1,-1}},
  {{0,0},{1,0},{1,1}},
  {{0,0},{1,0},{0,1}},
  {{0,0},{0,1},{1,1}}
};
int H, W;
//게임판의 상태. 0이면 흰 칸, 1이면 검은 칸
bool board[20][20];
//t type으로 {y,x}에서 게임판을 덮을 때 판을 넘거나 검은칸과 겹치면 false. 문제 없이 덮을 수 있으면 true
bool inRange(int y, int x, int t){
  for(int i=1; i<3; i++){
    int ny=y+type[t][i][0], nx=x+type[t][i][1];
    if(ny<0||nx<0||ny>=H||nx>=W||board[ny][nx]) return false;
  }
  return true;
}
//t type으로 {y,x}에서 게임판을 덮는다
void cover(int y, int x, int t){
  for(int i=0; i<3; i++){
    int ny=y+type[t][i][0], nx=x+type[t][i][1];
    board[ny][nx] = !board[ny][nx];
  }
}

int countCover(int lastH=0){
  int y=-1, x=-1;
  for(int i=lastH; i<H; i++){
    for(int j=0; j<W; j++)
      if(!board[i][j]){
        y=i, x=j;
        break;
      }
    if(y!=-1) break;
  }
  //더 이상 덮을 흰 칸이 없는 경우
  if(y==-1&&x==-1) return 1;
  //4가지 방법으로 흰 칸을 덮으려고 시도한다
  int res=0;
  for(int i=0; i<4; i++)
    if(inRange(y,x,i)){
      cover(y,x,i);
      res += countCover(y);
      cover(y,x,i);
    }
  return res;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int C;
  cin >> C;
  while(C--){
    cin >> H >> W;
    for(int i=0; i<H; i++)
      for(int j=0; j<W; j++){
        char ch;
        cin >> ch;
        board[i][j] = (ch=='#' ? 1 : 0);
      }
    cout << countCover() << endl;
  }
}

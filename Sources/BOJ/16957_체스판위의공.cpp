#include <iostream>
#include <cstring>
using namespace std;
const int MAX=500, dr[8]={-1,-1,-1,0,0,1,1,1}, dc[8]={-1,0,1,-1,1,-1,0,1};
//체스판에 적혀있는 정수
int board[500][500];

//유니온파인드 알고리즘
//uf[i][j] = 체스판에서 i행 j열에 있는 공이 최종적으로 가는 칸. 최종 칸이라면 음수로 그 칸에 모이는 공의 개수를 가진다.
int uf[500][500];
//n에서 시작해 공이 최종적으로 가는 칸의 번호를 반환한다
int find(int n){
  if(uf[n/MAX][n%MAX]<0) return n;
  return uf[n/MAX][n%MAX]=find(uf[n/MAX][n%MAX]);
}
//u로 v에 있는 공이 가도록 한다
void merge(int u, int v){
  u=find(u), v=find(v);
  if(u==v) return;
  //u에 모인 공의 개수 최신화
  uf[u/MAX][u%MAX]+=uf[v/MAX][v%MAX];
  //v에 오는 공들이 u로 가도록 한다
  uf[v/MAX][v%MAX]=u;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int R, C;
  cin >> R >> C;
  for(int i=0; i<R; i++)
    for(int j=0; j<C; j++) cin >> board[i][j];
  
  memset(uf, -1, sizeof(uf));
  for(int r=0; r<R; r++)
    for(int c=0; c<C; c++){
      int minR=r, minC=c;
      //인접한 8방향에서 현재 칸보다 작은 가장 작은 정수가 있는 칸의 좌표를 찾는다
      for(int i=0; i<8; i++){
        int nr=r+dr[i], nc=c+dc[i];
        if(nr<0||nc<0||nr>=R||nc>=C) continue;
        if(board[nr][nc]<board[minR][minC]) minR=nr, minC=nc;
      }
      //인접한 가장 작은 정수가 있는 칸에 현재 칸의 공이 가도록 한다
      merge(minR*MAX+minC, r*MAX+c);
    }
  
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++)
      cout << (uf[i][j]<0 ? -uf[i][j] : 0) << ' ';
    cout << '\n';
  }
}

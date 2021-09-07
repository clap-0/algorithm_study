#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int d1[4][2]={{-1,0},{0,1},{1,0},{0,-1}}, d2[4][2]={{-1,-1},{-1,1},{1,1},{1,-1}};
int main()
{
  int R1, C1, R2, C2;
  queue<int> Q;
  int discovered[10][9];
  cin >> R1 >> C1 >> R2 >> C2;
  //너비우선탐색
  Q.push(R1*9+C1);
  memset(discovered, -1, sizeof(discovered));
  discovered[R1][C1]=0;
  //상이 더 이상 갈 곳이 없거나 왕을 잡을 때까지 반복
  while(!Q.empty()&&discovered[R2][C2]==-1){
    int r=Q.front()/9, c=Q.front()%9;
    Q.pop();
    for(int i=0; i<4; i++){
      int tmpR=r+d1[i][0], tmpC=c+d1[i][1];
      //상의 상하좌우에 기물(왕)이 있는 경우 가지 못한다
      if(tmpR==R2&&tmpC==C2) continue;
      for(int j=0; j<2; j++){
        int nr=tmpR+2*d2[(i+j)%4][0], nc=tmpC+2*d2[(i+j)%4][1];
        //상의 목적지가 장기판 밖이거나 목적지로 가는 도중 기물(왕)이 있는 경우 가지 못한다
        if(nr<0||nc<0||nr>=10||nc>=9||(nr-d2[(i+j)%4][0]==R2&&nc-d2[(i+j)%4][1]==C2)) continue;
        //아직 방문하지 않은 칸인 경우
        if(discovered[nr][nc]==-1){
          discovered[nr][nc]=discovered[r][c]+1;
          Q.push(nr*9+nc);
        }
      }
    }
  }
  cout << discovered[R2][C2] << '\n';
}

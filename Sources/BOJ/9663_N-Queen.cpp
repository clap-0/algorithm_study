#include <iostream>
using namespace std;

int n;
int Queens[15]; //Queen[i] = i행의 퀸이 있는 열번호

//백트래킹을 이용해 퀸을 놓는 방법의 수를 구함
//n*n 체스판 위에 퀸 n개가 있으려면 각 행에 퀸이 하나씩 있어야 하므로
//한 행의 모든 칸에 퀸이 올 수 없으면 이전 행의 퀸 위치를 바꾼다
int N_Queen(int y){
  if(y==n) return 1; //기저사례 : 마지막 행까지 퀸을 놓으면 방법 하나 찾음
  
  int ret=0;
  for(int x=0; x<n; x++){
    bool canPlace=true; //y행 x열에 퀸을 둘 수 있는가
    
    //이전 행의 퀸들을 공격할 수 있으면 현위치 불가능
    for(int row=0; row<y; row++)
      if(Queens[row]==x || y-row==x-Queens[row] || y-row==Queens[row]-x){
        canPlace=false;
        break;
      }
    
    if(canPlace){
      Queens[y]=x;
      ret+=N_Queen(y+1);
    }
  }
  return ret;
}

int main()
{
  cin >> n;
  cout << N_Queen(0) << '\n';
}

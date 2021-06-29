#include <cstdio>
using namespace std;
const int MAX=2187;
//stars[i][j] = true면 해당 위치에 별표, false면 공백
bool stars[MAX][MAX];
//분할정복
void solve(int y, int x, int n){
  //기저사례 : 크기가 1인 경우 해당 위치에 별표를 표시한다
  if(n==1){
    stars[y][x]=true;
    return;
  }
  //가운데를 제외한 모든 칸에 별을 찍는다
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      if(!(i==1&&j==1)) solve(y+i*n/3,x+j*n/3,n/3);
}
int main()
{
  int N;
  scanf("%d", &N);
  solve(0,0,N);
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(stars[i][j]) printf("*");
      else printf(" ");
    }
    puts("");
  }
}

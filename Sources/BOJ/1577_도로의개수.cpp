#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M, K;
long long cache[101][101][2];
//DP를 이용하여 (x,y)로 passedDir방향에서 왔을 때
//이 위치에서 (N,M)까지 가는 경로의 경우의 수를 구한다
//passedDir==1이면 가로방향, 0이면 세로방향의 길을 통해 왔다
long long countPath(int x, int y, int passedDir){
  //메모이제이션
  long long& ret = cache[x][y][passedDir];
  if(ret!=-1) return ret;
  //기저사례: 목적지에 도착한 경우 1 반환
  if(x==N && y==M) return ret=1;
  ret=0;
  //현 위치에서 가로방향길로 간다
  if(x<N) ret+=countPath(x+1, y, 1);
  //현 위치에서 세로방향길로 간다
  if(y<M) ret+=countPath(x, y+1, 0);
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  memset(cache, -1, sizeof(cache));
  cin >> N >> M;
  cin >> K;
  for(int i=0; i<K; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    //(a,b)가 무조건 (c,d)보다 목적지에 가깝게 만든다
    if(a<c||b<d){
      swap(a,c);
      swap(b,d);
    }
    //공사중인 길목을 통한 경우의 수는 미리 0으로 계산한다
    cache[a][b][a==c+1]=0;
  }
  cout << countPath(0, 0, 0) << '\n';
}

#include <iostream>
#include <cstring>
using namespace std;
const int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};
int n, bamboo[500][500], cache[500][500];
//DP를 이용하여 (y,x)칸에서 시작해 판다가 이동할 수 있는 칸의 수의 최댓값을 구한다
int moveFrom(int y, int x){
  //메모이제이션
  int& ret = cache[y][x];
  if(ret!=-1) return ret;
  ret=1;
  //상하좌우에 이 칸보다 대나무가 많은 칸이 있는지 찾아본다
  for(int i=0; i<4; i++){
    int ny=y+dy[i], nx=x+dx[i];
    if(ny<0||nx<0||ny>=n||nx>=n) continue;
    if(bamboo[ny][nx]>bamboo[y][x]) ret=max(ret, moveFrom(ny,nx)+1);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++) cin >> bamboo[i][j];
  memset(cache, -1, sizeof(cache));
  int ans=0;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++) ans=max(ans, moveFrom(i,j));
  cout << ans << '\n';
}

#include <iostream>
#include <cstring>
using namespace std;
const int dy[4]={-1,0,0,1}, dx[4]={0,-1,1,0};
int N, M, K, wordLen;
string word;
char board[100][100];
int cache[80][10000];
//DP를 이용하여 문자판의 pos칸에서 word[w..]를 만들 수 있는 경로의 개수를 구한다
//이때 pos칸의 문자는 무조건 word[w]와 같다
int countPath(int w, int pos){
  //메모이제이션
  int& ret=cache[w][pos];
  if(ret!=-1) return ret;
  //경로를 하나 찾은 경우 1반환
  if(w==wordLen-1) return ret=1;
  ret=0;
  int y=pos/100, x=pos%100;
  for(int k=1; k<=K; k++)
    for(int d=0; d<4; d++){
      int ny=y+k*dy[d], nx=x+k*dx[d];
      //문자판의 범위를 벗어나거나 해당 칸에 쓰여진 문자가 찾아야 할 문자와 다른 경우
      if(ny<0||nx<0||ny>=N||nx>=M||board[ny][nx]!=word[w+1]) continue;
      ret+=countPath(w+1, ny*100+nx);
    }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> M >> K;
  for(int i=0; i<N; i++) cin >> board[i];
  cin >> word;
  memset(cache, -1, sizeof(cache));
  wordLen=word.length();
  int ans=0;
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      if(board[i][j]==word[0]) ans+=countPath(0, i*100+j);
  cout << ans << '\n';
}

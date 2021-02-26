#include <iostream>
#include <algorithm>
using namespace std;
char board[50][50];

int countSquares(int y, int x)
{
	int cnt=0;
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j+=2)
		{
			if(i%2){
			  if(board[y+i][x+j]==board[y][x]) cnt++;
			}
			else{
				if(board[y+i][x+j]!=board[y][x]) cnt++;
			}
		}
		for(int j=1; j<8; j+=2)
		{
			if(i%2){
				if(board[y+i][x+j]!=board[y][x]) cnt++;
			}
			else{
				if(board[y+i][x+j]==board[y][x]) cnt++;
			}
		}
	}
	return min(cnt, 64-cnt);
}
int main()
{
	int n, m, res=987654321;
	cin >> n >> m;
  for(int i=0; i<n; i++){
  	for(int j=0; j<m; j++){
  		cin >> board[i][j];
  	}
  }
  for(int i=0; i<=n-8; i++){
  	for(int j=0; j<=m-8; j++){
  		res = min(res, countSquares(i, j));
  	}
  }
  cout << res << endl;
	return 0;
}

#include <iostream>
using namespace std;
int square[128][128];
int numSquares[2];
void countSquares(int y, int x, int size)
{
  int check = square[y][x];
  for(int dy=0; dy<size; dy++){
    for(int dx=0; dx<size; dx++){
      if(check!=square[y+dy][x+dx]){
        int half = size/2;
        countSquares(y, x, half);
        countSquares(y, x+half, half);
        countSquares(y+half, x, half);
        countSquares(y+half, x+half, half);
        return;
      }
    }
  }
  numSquares[square[y][x]]++; //정사각형이 같은색으로 칠해져 있을 때
  return;
}
int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> square[i][j];
  countSquares(0, 0, n);
  cout << numSquares[0] << endl << numSquares[1] << endl;
  return 0;
}

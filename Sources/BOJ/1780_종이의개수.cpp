#include <iostream>
using namespace std;
int square[2187][2187];
int ans[3];
int d[9][2]={
{0,0}, {0,1}, {0,2},
{1,0}, {1,1}, {1,2},
{2,0}, {2,1}, {2,2}
};
void cutPaper(int y, int x, int size)
{
  int check=square[y][x];
  for(int dy=0; dy<size; dy++){
    for(int dx=0; dx<size; dx++){
      if(check!=square[y+dy][x+dx]){
        int oneThird = size/3;
        for(int i=0; i<9; i++)
          cutPaper(y+d[i][0]*oneThird, x+d[i][1]*oneThird, oneThird);
        return;
      }
    }
  }
  ans[check+1]++;
}
int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> square[i][j];
  cutPaper(0, 0, n);
  for(int i=0; i<3; i++)
    cout << ans[i] << endl;
  return 0;
}

#include <iostream>
using namespace std;
char square[64][64];
void compress(int y, int x, int size)
{
  char check=square[y][x];
  for(int dy=0; dy<size; dy++)
    for(int dx=0; dx<size; dx++)
      if(check!=square[y+dy][x+dx]){
        cout << '(';
        int half=size/2;
        compress(y,x,half);
        compress(y,x+half,half);
        compress(y+half,x,half);
        compress(y+half,x+half,half);
        cout << ')';
        return;
      }
  cout << check;
  return;
}
int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++) cin >> square[i];
  compress(0, 0, n);
  return 0;
}
